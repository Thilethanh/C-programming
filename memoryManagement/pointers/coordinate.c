#include "coordinate.h"

void coordinate_update_x(coordinate_t coord, int new_x) {
  coord.x = new_x;
}

coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x) {
  coord.x = new_x;
  
  return coord;
}


// Python could use a class to store the data,
// and pass an instance of that class into the function
/*
 *
 class Coordinate:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

def update_coordinate_x(coord, new_x):
    coord.x = new_x

c = Coordinate(1, 2, 3)
print(c.x)  # 1
update_coordinate_x(c, 4)
print(c.x)  # 4

*/
