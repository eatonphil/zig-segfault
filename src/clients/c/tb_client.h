 //////////////////////////////////////////////////////////
 // This file was auto-generated by tb_client_header.zig //
 //              Do not manually modify.                 //
 //////////////////////////////////////////////////////////

#ifndef TB_CLIENT_H
#define TB_CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif
 
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef __uint128_t tb_uint128_t;

typedef enum TB_ACCOUNT_FLAGS {
    TB_ACCOUNT_LINKED = 1 << 0,
    TB_ACCOUNT_DEBITS_MUST_NOT_EXCEED_CREDITS = 1 << 1,
    TB_ACCOUNT_CREDITS_MUST_NOT_EXCEED_DEBITS = 1 << 2,
} TB_ACCOUNT_FLAGS;

typedef struct tb_account_t {
    tb_uint128_t id;
    tb_uint128_t user_data;
    uint8_t reserved[48];
    uint32_t ledger;
    uint16_t code;
    uint16_t flags;
    uint64_t debits_pending;
    uint64_t debits_posted;
    uint64_t credits_pending;
    uint64_t credits_posted;
    uint64_t timestamp;
} tb_account_t;

typedef enum TB_TRANSFER_FLAGS {
    TB_TRANSFER_LINKED = 1 << 0,
    TB_TRANSFER_PENDING = 1 << 1,
    TB_TRANSFER_POST_PENDING_TRANSFER = 1 << 2,
    TB_TRANSFER_VOID_PENDING_TRANSFER = 1 << 3,
    TB_TRANSFER_BALANCING_DEBIT = 1 << 4,
    TB_TRANSFER_BALANCING_CREDIT = 1 << 5,
} TB_TRANSFER_FLAGS;

typedef struct tb_transfer_t {
    tb_uint128_t id;
    tb_uint128_t debit_account_id;
    tb_uint128_t credit_account_id;
    tb_uint128_t user_data;
    tb_uint128_t reserved;
    tb_uint128_t pending_id;
    uint64_t timeout;
    uint32_t ledger;
    uint16_t code;
    uint16_t flags;
    uint64_t amount;
    uint64_t timestamp;
} tb_transfer_t;

typedef enum TB_CREATE_ACCOUNT_RESULT {
    TB_CREATE_ACCOUNT_OK = 0,
    TB_CREATE_ACCOUNT_LINKED_EVENT_FAILED = 1,
    TB_CREATE_ACCOUNT_LINKED_EVENT_CHAIN_OPEN = 2,
    TB_CREATE_ACCOUNT_TIMESTAMP_MUST_BE_ZERO = 3,
    TB_CREATE_ACCOUNT_RESERVED_FLAG = 4,
    TB_CREATE_ACCOUNT_RESERVED_FIELD = 5,
    TB_CREATE_ACCOUNT_ID_MUST_NOT_BE_ZERO = 6,
    TB_CREATE_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 7,
    TB_CREATE_ACCOUNT_FLAGS_ARE_MUTUALLY_EXCLUSIVE = 8,
    TB_CREATE_ACCOUNT_LEDGER_MUST_NOT_BE_ZERO = 9,
    TB_CREATE_ACCOUNT_CODE_MUST_NOT_BE_ZERO = 10,
    TB_CREATE_ACCOUNT_DEBITS_PENDING_MUST_BE_ZERO = 11,
    TB_CREATE_ACCOUNT_DEBITS_POSTED_MUST_BE_ZERO = 12,
    TB_CREATE_ACCOUNT_CREDITS_PENDING_MUST_BE_ZERO = 13,
    TB_CREATE_ACCOUNT_CREDITS_POSTED_MUST_BE_ZERO = 14,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_FLAGS = 15,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_USER_DATA = 16,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_LEDGER = 17,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_CODE = 18,
    TB_CREATE_ACCOUNT_EXISTS = 19,
} TB_CREATE_ACCOUNT_RESULT;

typedef enum TB_CREATE_TRANSFER_RESULT {
    TB_CREATE_TRANSFER_OK = 0,
    TB_CREATE_TRANSFER_LINKED_EVENT_FAILED = 1,
    TB_CREATE_TRANSFER_LINKED_EVENT_CHAIN_OPEN = 2,
    TB_CREATE_TRANSFER_TIMESTAMP_MUST_BE_ZERO = 3,
    TB_CREATE_TRANSFER_RESERVED_FLAG = 4,
    TB_CREATE_TRANSFER_RESERVED_FIELD = 5,
    TB_CREATE_TRANSFER_ID_MUST_NOT_BE_ZERO = 6,
    TB_CREATE_TRANSFER_ID_MUST_NOT_BE_INT_MAX = 7,
    TB_CREATE_TRANSFER_FLAGS_ARE_MUTUALLY_EXCLUSIVE = 8,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_ID_MUST_NOT_BE_ZERO = 9,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 10,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_ID_MUST_NOT_BE_ZERO = 11,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 12,
    TB_CREATE_TRANSFER_ACCOUNTS_MUST_BE_DIFFERENT = 13,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_BE_ZERO = 14,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_NOT_BE_ZERO = 15,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_NOT_BE_INT_MAX = 16,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_BE_DIFFERENT = 17,
    TB_CREATE_TRANSFER_TIMEOUT_RESERVED_FOR_PENDING_TRANSFER = 18,
    TB_CREATE_TRANSFER_LEDGER_MUST_NOT_BE_ZERO = 19,
    TB_CREATE_TRANSFER_CODE_MUST_NOT_BE_ZERO = 20,
    TB_CREATE_TRANSFER_AMOUNT_MUST_NOT_BE_ZERO = 21,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_NOT_FOUND = 22,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_NOT_FOUND = 23,
    TB_CREATE_TRANSFER_ACCOUNTS_MUST_HAVE_THE_SAME_LEDGER = 24,
    TB_CREATE_TRANSFER_TRANSFER_MUST_HAVE_THE_SAME_LEDGER_AS_ACCOUNTS = 25,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_NOT_FOUND = 26,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_NOT_PENDING = 27,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_DEBIT_ACCOUNT_ID = 28,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_CREDIT_ACCOUNT_ID = 29,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_LEDGER = 30,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_CODE = 31,
    TB_CREATE_TRANSFER_EXCEEDS_PENDING_TRANSFER_AMOUNT = 32,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_AMOUNT = 33,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_ALREADY_POSTED = 34,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_ALREADY_VOIDED = 35,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_EXPIRED = 36,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_FLAGS = 37,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_DEBIT_ACCOUNT_ID = 38,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_CREDIT_ACCOUNT_ID = 39,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_PENDING_ID = 40,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_USER_DATA = 41,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_TIMEOUT = 42,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_CODE = 43,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_AMOUNT = 44,
    TB_CREATE_TRANSFER_EXISTS = 45,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS_PENDING = 46,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS_PENDING = 47,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS_POSTED = 48,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS_POSTED = 49,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS = 50,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS = 51,
    TB_CREATE_TRANSFER_OVERFLOWS_TIMEOUT = 52,
    TB_CREATE_TRANSFER_EXCEEDS_CREDITS = 53,
    TB_CREATE_TRANSFER_EXCEEDS_DEBITS = 54,
} TB_CREATE_TRANSFER_RESULT;

typedef struct tb_create_accounts_result_t {
    uint32_t index;
    uint32_t result;
} tb_create_accounts_result_t;

typedef struct tb_create_transfers_result_t {
    uint32_t index;
    uint32_t result;
} tb_create_transfers_result_t;

typedef enum TB_OPERATION {
    TB_OPERATION_CREATE_ACCOUNTS = 128,
    TB_OPERATION_CREATE_TRANSFERS = 129,
    TB_OPERATION_LOOKUP_ACCOUNTS = 130,
    TB_OPERATION_LOOKUP_TRANSFERS = 131,
} TB_OPERATION;

typedef enum TB_PACKET_STATUS {
    TB_PACKET_OK = 0,
    TB_PACKET_TOO_MUCH_DATA = 1,
    TB_PACKET_INVALID_OPERATION = 2,
    TB_PACKET_INVALID_DATA_SIZE = 3,
} TB_PACKET_STATUS;

typedef enum TB_PACKET_ACQUIRE_STATUS {
    TB_PACKET_ACQUIRE_OK = 0,
    TB_PACKET_ACQUIRE_CONCURRENCY_MAX_EXCEEDED = 1,
    TB_PACKET_ACQUIRE_SHUTDOWN = 2,
} TB_PACKET_ACQUIRE_STATUS;

typedef struct tb_packet_t {
    struct tb_packet_t* next;
    void* user_data;
    uint8_t operation;
    uint8_t status;
    uint32_t data_size;
    void* data;
} tb_packet_t;

typedef void* tb_client_t; 

typedef enum TB_STATUS {
    TB_STATUS_SUCCESS = 0,
    TB_STATUS_UNEXPECTED = 1,
    TB_STATUS_OUT_OF_MEMORY = 2,
    TB_STATUS_ADDRESS_INVALID = 3,
    TB_STATUS_ADDRESS_LIMIT_EXCEEDED = 4,
    TB_STATUS_CONCURRENCY_MAX_INVALID = 5,
    TB_STATUS_SYSTEM_RESOURCES = 6,
    TB_STATUS_NETWORK_SUBSYSTEM = 7,
} TB_STATUS;

TB_STATUS tb_client_init(
    tb_client_t* out_client,
    uint32_t cluster_id,
    const char* address_ptr,
    uint32_t address_len,
    uint32_t packets_count,
    uintptr_t on_completion_ctx,
    void (*on_completion_fn)(uintptr_t, tb_client_t, tb_packet_t*, const uint8_t*, uint32_t)
);

TB_STATUS tb_client_init_echo(
    tb_client_t* out_client,
    uint32_t cluster_id,
    const char* address_ptr,
    uint32_t address_len,
    uint32_t packets_count,
    uintptr_t on_completion_ctx,
    void (*on_completion_fn)(uintptr_t, tb_client_t, tb_packet_t*, const uint8_t*, uint32_t)
);

TB_PACKET_ACQUIRE_STATUS tb_client_acquire_packet(
    tb_client_t client,
    tb_packet_t** out_packet
);

void tb_client_release_packet(
    tb_client_t client,
    tb_packet_t* packet
);

void tb_client_submit(
    tb_client_t client,
    tb_packet_t* packet
);

void tb_client_deinit(
    tb_client_t client
);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TB_CLIENT_H