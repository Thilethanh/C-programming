// Union
//
#include <stdio.h>
#include "munit.h"
#include "exercise.h"

/* -------- Tests -------- */

static MunitResult test_formats_int1(const MunitParameter params[], void *data) {
    char buffer[100];
    snek_object_t i = new_integer(5);
    format_object(i, buffer);

    munit_assert_string_equal(buffer, "int:5");
    return MUNIT_OK;
}

static MunitResult test_formats_string1(const MunitParameter params[], void *data) {
    char buffer[100];
    snek_object_t s = new_string("Hello!");
    format_object(s, buffer);

    munit_assert_string_equal(buffer, "string:Hello!");
    return MUNIT_OK;
}

static MunitResult test_formats_int2(const MunitParameter params[], void *data) {
    char buffer[100];
    snek_object_t i = new_integer(2014);
    format_object(i, buffer);

    munit_assert_string_equal(buffer, "int:2014");
    return MUNIT_OK;
}

static MunitResult test_formats_string2(const MunitParameter params[], void *data) {
    char buffer[100];
    snek_object_t s = new_string("nvim btw");
    format_object(s, buffer);

    munit_assert_string_equal(buffer, "string:nvim btw");
    return MUNIT_OK;
}

/* -------- Test Registry -------- */

static MunitTest tests[] = {
    { "/integer",        test_formats_int1,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/string",         test_formats_string1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/integer_nvim",   test_formats_int2,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/string_nvim",    test_formats_string2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/format",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

