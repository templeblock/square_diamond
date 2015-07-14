#ifndef MAP_H
#define MAP_H

#include <stdlib.h>

typedef struct {
    int **height;        /* Array of the heights of points in the plane. */
    size_t side_len;     /* Internal width and height of map. */
    size_t random_range; /* The range the height can change. */
    int water_height;    /* The height of any water on the map. */
    size_t max;          /* The maximum height on the map. */
} map_t;

#define AVERAGE(x, y) ((x + y) / 2)

/* Initializes the map, the higher the random range, the more hilly the terrain
 * will be. */
int map_init(map_t *m, size_t side_len, size_t random_range, size_t max_height);

/* Returns the height of the map in a specific point. */
int map_get_height(map_t const *m, int x, int y);

/* Set the height of the map in a specific point. */
void map_set_height(map_t *m, int x, int y, int value);

/* Set a height for water. */
void map_set_water_height(map_t *m, int new_height);

/* Run the square diamond algorithm on the map to generate a terrain. */
void map_square_diamond(map_t *m);

/* Save the map as a png image. */
int map_save_as_png(map_t const *m, char const *filename, size_t height,
        size_t width);

/* Compare two map_t's by comparing all metadata about the maps. The function
 * does not actually compare all points on the map. */
inline int map_shallow_cmp(map_t const *m1, map_t const *m2);

#endif