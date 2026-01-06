#include <stdlib.h>
#include "exercise.h"
#include "munit.h"

/* ---------- Tests ---------- */

static MunitResult
test_allocate_scalar_array_size(const MunitParameter params[], void *data) {
    (void) params; (void) data;

    int *result = allocate_scalar_array(5, 2);
    munit_assert_not_null(result);
    free(result);

    return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_array_values(const MunitParameter params[], void *data) {
    (void) params; (void) data;

    int *result = allocate_scalar_array(5, 2);
    int expected[5] = {0, 2, 4, 6, 8};

    for (int i = 0; i < 5; i++)
        munit_assert_int(result[i], ==, expected[i]);

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_array_zero_multiplier(const MunitParameter params[], void *data) {
    (void) params; (void) data;

    int *result = allocate_scalar_array(3, 0);

    for (int i = 0; i < 3; i++)
        munit_assert_int(result[i], ==, 0);

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_allocate_too_much(const MunitParameter params[], void *data) {
    (void) params; (void) data;

    int size = (64 * 1024 * 1024) / sizeof(int);
    int *result = allocate_scalar_array(size, 1);

    if (result != NULL) {
        munit_assert_int(result[0], ==, 0);
        munit_assert_int(result[size - 1], ==, size - 1);
        free(result);
    }

    return MUNIT_OK;
}

/* ---------- Test Registry ---------- */

int main(void) {
    MunitTest tests[] = {
        { "/size", test_allocate_scalar_array_size, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/values", test_allocate_scalar_array_values, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/zero_multiplier", test_allocate_scalar_array_zero_multiplier, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/too_much", test_allocate_too_much, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/allocate_scalar_array",
        tests,
        NULL,
        1,
        MUNIT_SUITE_OPTION_NONE
    };

    return munit_suite_main(&suite, NULL, 0, NULL);
}

