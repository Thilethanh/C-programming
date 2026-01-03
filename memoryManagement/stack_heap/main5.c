#include "munit.h"
#include "exercise.h"
#include <stdlib.h>

/* ---------- Tests ---------- */

static MunitResult
test_allocate_scalar_array_size(const MunitParameter params[], void* data) {
    int size = 5;
    int multiplier = 2;

    int *result = allocate_scalar_array(size, multiplier);
    munit_assert_not_null(result);

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_array_values(const MunitParameter params[], void* data) {
    int size = 5;
    int multiplier = 2;

    int *result = allocate_scalar_array(size, multiplier);
    munit_assert_not_null(result);

    int expected[] = {0, 2, 4, 6, 8};
    for (int i = 0; i < size; i++) {
        munit_assert_int(result[i], ==, expected[i]);
    }

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_array_zero_multiplier(const MunitParameter params[], void* data) {
    int size = 3;
    int multiplier = 0;

    int *result = allocate_scalar_array(size, multiplier);
    munit_assert_not_null(result);

    for (int i = 0; i < size; i++) {
        munit_assert_int(result[i], ==, 0);
    }

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_allocate_too_much(const MunitParameter params[], void* data) {
    int size = 1024 * 1024 * 100;
    int multiplier = 1;

    int *result = allocate_scalar_array(size, multiplier);
    munit_assert_null(result);

    return MUNIT_OK;
}

/* ---------- Test Registry ---------- */

int main(void) {
    MunitTest tests[] = {
        munit_test("/allocate/size", test_allocate_scalar_array_size),
        munit_test("/allocate/values", test_allocate_scalar_array_values),
        munit_test("/allocate/zero_multiplier", test_allocate_scalar_array_zero_multiplier),
        munit_test("/allocate/too_much", test_allocate_too_much),
        munit_null_test,
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

