// Pointers to the Stack
//
#include <stdio.h>

typedef struct {
  int x;
  int y;
} coord_t;

/* //Segmentation fault
 *
 coord_t *new_coord(int x, int y) {
  coord_t c;
  c.x = x;
  c.y = y;
  return &c;
}

int main() {
  coord_t *c1 = new_coord(10, 20);
  coord_t *c2 = new_coord(30, 40);
  coord_t *c3 = new_coord(50, 60);

  printf("c1: %d, %d\n", c1->x, c1->y);
  printf("c2: %d, %d\n", c2->x, c2->y);
  printf("c3: %d, %d\n", c3->x, c3->y);
}
*/

/* PROBLEM
- Stack memory is reclaimed when the function returns
- You cannot return pointers to stack objects
- This violates C object lifetime rules
*/
coord_t new_coord(int x, int y) {
  coord_t c;
  c.x = x;
  c.y = y;
  return c;
}

int main() {
  coord_t c1 = new_coord(10, 20);
  coord_t c2 = new_coord(30, 40);
  coord_t c3 = new_coord(50, 60);

  printf("c1: %d, %d\n", c1.x, c1.y);
  printf("c2: %d, %d\n", c2.x, c2.y);
  printf("c3: %d, %d\n", c3.x, c3.y);
}

