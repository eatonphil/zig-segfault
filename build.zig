const std = @import("std");
const builtin = @import("builtin");
const CrossTarget = std.zig.CrossTarget;
const Mode = std.builtin.Mode;

const config = @import("./src/config.zig");
const Shell = @import("./src/shell.zig");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const options = b.addOptions();

    const vsr_package = std.build.Pkg{
        .name = "vsr",
        .path = .{ .path = "src/vsr.zig" },
        .dependencies = &.{options.getPackage("vsr_options")},
    };

    const tigerbeetle = b.addExecutable("tigerbeetle", "src/tigerbeetle/main.zig");
    tigerbeetle.setTarget(target);
    tigerbeetle.setBuildMode(mode);
    tigerbeetle.addPackage(vsr_package);
    tigerbeetle.install();
    // Ensure that we get stack traces even in release builds.
    tigerbeetle.omit_frame_pointer = false;
    tigerbeetle.addOptions("vsr_options", options);

    {
        const run_cmd = tigerbeetle.run();
        if (b.args) |args| run_cmd.addArgs(args);

        const run_step = b.step("run", "Run TigerBeetle");
        run_step.dependOn(&run_cmd.step);
    }

    {
        // "zig build install" moves the server executable to the root folder:
        const move_cmd = b.addInstallBinFile(
            tigerbeetle.getOutputSource(),
            b.pathJoin(&.{ "../../", tigerbeetle.out_filename }),
        );
        move_cmd.step.dependOn(&tigerbeetle.step);

        const install_step = b.getInstallStep();
        install_step.dependOn(&move_cmd.step);
    }

    // Executable which generates src/clients/c/tb_client.h
    const tb_client_header_generate = blk: {
        const tb_client_header = b.addExecutable("tb_client_header", "src/clients/c/tb_client_header.zig");
        tb_client_header.addOptions("vsr_options", options);
        tb_client_header.setMainPkgPath("src");
        tb_client_header.setTarget(target);
        break :blk tb_client_header.run();
    };

    {
        const test_filter = b.option(
            []const u8,
            "test-filter",
            "Skip tests that do not match filter",
        );

        const unit_tests = b.addTest("src/unit_tests.zig");
        unit_tests.setTarget(target);
        unit_tests.setBuildMode(mode);
        unit_tests.addPackage(vsr_package);
        unit_tests.addOptions("vsr_options", options);
        unit_tests.step.dependOn(&tb_client_header_generate.step);
        unit_tests.setFilter(test_filter);

        // for src/clients/c/tb_client_header_test.zig to use cImport on tb_client.h
        unit_tests.linkLibC();
        unit_tests.addIncludeDir("src/clients/c/");

        const unit_tests_step = b.step("test:unit", "Run the unit tests");
        unit_tests_step.dependOn(&unit_tests.step);

        const test_step = b.step("test", "Run the unit tests");
        test_step.dependOn(&unit_tests.step);
        if (test_filter == null) {
            // Test that our demos compile, but don't run them.
            inline for (.{
                "demo_01_create_accounts",
                "demo_02_lookup_accounts",
                "demo_03_create_transfers",
                "demo_04_create_pending_transfers",
                "demo_05_post_pending_transfers",
                "demo_06_void_pending_transfers",
                "demo_07_lookup_transfers",
            }) |demo| {
                const demo_exe = b.addExecutable(demo, "src/demos/" ++ demo ++ ".zig");
                demo_exe.addPackage(vsr_package);
                demo_exe.setTarget(target);
                test_step.dependOn(&demo_exe.step);
            }
        }

        const unit_tests_exe = b.addTestExe("tests", "src/unit_tests.zig");
        unit_tests_exe.setTarget(target);
        unit_tests_exe.setBuildMode(mode);
        unit_tests_exe.addOptions("vsr_options", options);
        unit_tests_exe.step.dependOn(&tb_client_header_generate.step);
        unit_tests_exe.setFilter(test_filter);

        // for src/clients/c/tb_client_header_test.zig to use cImport on tb_client.h
        unit_tests_exe.linkLibC();
        unit_tests_exe.addIncludeDir("src/clients/c/");

        const unit_tests_exe_step = b.step("test:build", "Build the unit tests");
        const install_unit_tests_exe = b.addInstallArtifact(unit_tests_exe);
        unit_tests_exe_step.dependOn(&install_unit_tests_exe.step);
    }

    const cli_client_integration_build = b.step("cli_client_integration", "Build cli client integration test script.");
    const binary = b.addExecutable("cli_client_integration", "src/clients/cli_client_integration.zig");
    binary.setBuildMode(mode);
    binary.setTarget(target);
    cli_client_integration_build.dependOn(&binary.step);

    const install_step = b.addInstallArtifact(binary);
    cli_client_integration_build.dependOn(&install_step.step);
}
