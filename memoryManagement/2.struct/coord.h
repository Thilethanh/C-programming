#pragma once

/*
struct Coordinate {
	int x;
	int y;
	int z;
};

struct Coordinate new_coord(int x, int y, int z);
struct Coordinate scale_coordinate(struct Coordinate coord, int factor);
*/

// Update with typedef, less typing
//
typedef struct Coordinate {
  int x;
  int y;
  int z;
}coordinate_t;

coordinate_t new_coord(int x, int y, int z);
coordinate_t scale_coordinate(coordinate_t coord, int factor);

