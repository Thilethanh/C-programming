// Arrays Decay to Pointers
//
#include <stdio.h>

void core_utils_func(int core_utilization[]) {
  // 
  printf("sizeof core_utilization in core_utils_func: %zu\n", 
		  sizeof(core_utilization));
}

int main() {
  int core_utilization[] = {43, 67, 89, 92, 71, 43, 56, 12};
  int len = sizeof(core_utilization) / sizeof(core_utilization[0]);
  printf("sizeof core_utilization in main: %zu\n", sizeof(core_utilization));
  // 32 (8 eletments x 4 byte of int)
  printf("len of core_utilization: %d\n", len);
  // 8 (number of element)
  core_utils_func(core_utilization);
  /*
   Due to the array decaying to a pointer, the reported size is the size of a pointer, 
   not the size of the actual array.
   */
  return 0;
}
