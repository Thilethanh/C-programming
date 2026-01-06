// Operators

#include "munit.h"
#include "exercise.h"

static MunitResult test_snek_score_1(const MunitParameter params[], void* data) {
  float result = snek_score(3, 4, 5, 0.1);
  munit_assert_double_equal(result, 1.9, 2);
  // 2 - the precision (number of decimal places to check)
  return MUNIT_OK;
};

static MunitResult test_snek_score_2(const MunitParameter params[], void* data) {
  float result = snek_score(10, 10, 10, 0.1);
  munit_assert_double_equal(result, 11.0, 2);
  
  return MUNIT_OK;
};

static MunitResult test_snek_score_3(const MunitParameter params[], void* data) {
  float result = snek_score(105, 205, 207, 0.1);
  munit_assert_double_equal(result, 2194, 2);

  return MUNIT_OK;
};



static  MunitTest tests[] = {
 { "/test_snek_score_1", test_snek_score_1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
 { "/test_snek_score_2", test_snek_score_2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
 { "/test_snek_score_3", test_snek_score_3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
 { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};
/*
  { 
    "/test_name",              // test path/name
    test_function,              // pointer to the test function
    NULL,                       // setup function (optional)
    NULL,                       // teardown function (optional)
    MUNIT_TEST_OPTION_NONE,     // test options
    NULL                        // parameters (for parameterized tests)
i  },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // NULL terminator
};
*/

static const MunitSuite suite = {
  "/snek_score", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

