// Helper Fields
//
#include "munit.h"
#include "exercise.h"
#include <string.h>

/* ---------- Tests ---------- */

static MunitResult
test_packet_header_size(const MunitParameter params[], void* data) {
    munit_assert_size(sizeof(packet_header_t), ==, 8);
    return MUNIT_OK;
}

static MunitResult
test_tcp_header_fields(const MunitParameter params[], void* data) {
    packet_header_t header;

    header.tcp_header.src_port  = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num   = 0x9ABCDEF0;

    munit_assert_uint16(header.tcp_header.src_port, ==, 0x1234);
    munit_assert_uint16(header.tcp_header.dest_port, ==, 0x5678);
    munit_assert_uint32(header.tcp_header.seq_num, ==, 0x9ABCDEF0);

    return MUNIT_OK;
}

static MunitResult
test_field_raw_size(const MunitParameter params[], void* data) {
    munit_assert_size(sizeof(((packet_header_t*)0)->raw), ==, 8);
    return MUNIT_OK;
}

static MunitResult
test_field_to_raw_consistency(const MunitParameter params[], void* data) {
    packet_header_t header = {0};

    header.tcp_header.src_port  = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num   = 0x9ABCDEF0;

    munit_assert_uint8(header.raw[0], ==, 0x34);
    munit_assert_uint8(header.raw[1], ==, 0x12);
    munit_assert_uint8(header.raw[2], ==, 0x78);
    munit_assert_uint8(header.raw[3], ==, 0x56);
    munit_assert_uint8(header.raw[4], ==, 0xF0);
    munit_assert_uint8(header.raw[5], ==, 0xDE);
    munit_assert_uint8(header.raw[6], ==, 0xBC);
    munit_assert_uint8(header.raw[7], ==, 0x9A);

    return MUNIT_OK;
}

/* ---------- Test Registry ---------- */

static MunitTest tests[] = {
    {
        "/packet_header_size",
        test_packet_header_size,
        NULL, NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/tcp_header_fields",
        test_tcp_header_fields,
        NULL, NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/field_raw_size",
        test_field_raw_size,
        NULL, NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/field_to_raw_consistency",
        test_field_to_raw_consistency,
        NULL, NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/PacketHeader",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

/* ---------- Main ---------- */

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

