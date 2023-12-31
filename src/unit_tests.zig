test {
    _ = @import("tidy.zig");

    _ = @import("ewah.zig");
    _ = @import("fifo.zig");
    _ = @import("io.zig");
    _ = @import("ring_buffer.zig");
    _ = @import("stdx.zig");
    _ = @import("hash_map.zig");

    _ = @import("lsm/binary_search.zig");
    _ = @import("lsm/bloom_filter.zig");
    _ = @import("lsm/eytzinger.zig");
    _ = @import("lsm/forest.zig");
    _ = @import("lsm/groove.zig");
    _ = @import("lsm/k_way_merge.zig");
    _ = @import("lsm/manifest_level.zig");
    _ = @import("lsm/node_pool.zig");
    _ = @import("lsm/segmented_array.zig");
    _ = @import("lsm/set_associative_cache.zig");
    _ = @import("lsm/table.zig");
    _ = @import("lsm/tree.zig");

    _ = @import("state_machine.zig");
    _ = @import("state_machine/auditor.zig");
    _ = @import("state_machine/workload.zig");

    _ = @import("testing/id.zig");
    _ = @import("testing/storage.zig");
    _ = @import("testing/table.zig");

    // This one is a bit sketchy: we rely on tests not actually using the `vsr` package.
    _ = @import("tigerbeetle/cli.zig");

    _ = @import("tigerbeetle/client_test.zig");

    _ = @import("vsr.zig");
    _ = @import("vsr/clock.zig");
    _ = @import("vsr/checksum.zig");
    _ = @import("vsr/journal.zig");
    _ = @import("vsr/marzullo.zig");
    _ = @import("vsr/replica_format.zig");
    _ = @import("vsr/replica_test.zig");
    _ = @import("vsr/superblock.zig");
    _ = @import("vsr/superblock_free_set.zig");
    _ = @import("vsr/superblock_manifest.zig");
    _ = @import("vsr/superblock_quorums.zig");
    _ = @import("vsr/sync.zig");

    _ = @import("aof.zig");

    _ = @import("shell.zig");
}
