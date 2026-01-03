// main4.c - Heap
#include "munit.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "exercise.h"

/* Helper: check if pointer is on stack */
static bool is_on_stack(void *ptr) {
    void *stack_top = __builtin_frame_address(0);
    uintptr_t stack_top_addr = (uintptr_t)stack_top;
    uintptr_t ptr_addr = (uintptr_t)ptr;

    uintptr_t threshold = 1024; // 1 KB window
    return ptr_addr >= (stack_top_addr - threshold) &&
           ptr_addr <= (stack_top_addr + threshold);
}

/* -------- Tests -------- */

static MunitResult
test_basic_greeting(const MunitParameter params[], void *data) {
    (void)params; (void)data;

    char *result = get_full_greeting("Hello", "Alice", 20);

    munit_assert_string_equal(result, "Hello Alice");
    munit_assert_false(is_on_stack(result));

    free(result);
    return MUNIT_OK;
}

static MunitResult
test_short_buffer(const MunitParameter params[], void *data) {
    (void)params; (void)data;

    char *result = get_full_greeting("Hey", "Bob", 4);

    munit_assert_string_equal(result, "Hey");
    munit_assert_false(is_on_stack(result));

    free(result);
    return MUNIT_OK;
}

/* -------- Test table -------- */

static MunitTest tests[] = {
    {
        "/test_basic_greeting",
        test_basic_greeting,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/test_short_buffer",
        test_short_buffer,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/get_full_greeting",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
 
