// Topic unnittest
#include <stdio.h>

#include "munit.h"
#include "exercise.h"

static MunitResult test_get_average(const MunitParameter params[], void* data) {
  float result = get_average(3, 4, 5);
  munit_assert_double_equal(result, 4.0, 2);
  return MUNIT_OK;
}

static MunitResult test_non_integer(const MunitParameter params[], void* data) {
  float result = get_average(3, 3, 5);
  munit_assert_double_equal(result, 11.0 / 3.0, 2);
  return MUNIT_OK;
}

static MunitResult test_average_of_same(const MunitParameter params[], void* data) {
  float result2 = get_average(10, 10, 10);
  munit_assert_double_equal(result2, 10.0, 2);
  return MUNIT_OK;
}

static MunitResult test_average_of_big_numbers(const MunitParameter params[], void* data) {
  float result3 = get_average(1050, 2050, 2075);
  munit_assert_double_equal(result3, 1725.0, 2);
  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { "/test_get_average", test_get_average, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_non_integer", test_non_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_average_of_same", test_average_of_same, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_average_of_big_numbers", test_average_of_big_numbers, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  "/exercise", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}
