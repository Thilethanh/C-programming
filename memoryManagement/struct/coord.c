#include "coord.h"

/*
// Initializers
struct Coordinate new_coord(int x, int y, int z) {
  return( struct Coordinate){ .x = x, .y = y, .z = z};
}


// By returing a struct, we can have multiple values in return 
struct Coordinate scale_coordinate(struct Coordinate coord, int factor){
	 return (struct Coordinate){
		 .x = coord.x * factor,
        	 .y = coord.y * factor,
        	 .z = coord.z * factor
    };

}
*/

// Update using Typedef and show a different syntax

coordinate_t new_coord(int x, int y, int z) {
  coordinate_t coord = {.x = x, .y = y, .z = z};

  return coord;
}

coordinate_t scale_coordinate(coordinate_t coord, int factor) {
  coordinate_t scaled = coord;
  scaled.x *= factor;
  scaled.y *= factor;
  scaled.z *= factor;

  return scaled;
}




