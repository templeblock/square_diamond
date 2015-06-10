#ifndef MAP_H
#define MAP_H

typedef struct {
    int **height;     /* Array of the heights of points in the plane. */
    int length;       /* Length of plane. */
    int width;        /* Width of plane. */
    int random_range; /* The range the height can change. */
    int water_height; /* The height of any water on the map. */
} map_t;

#define AVERAGE(x, y) ((x + y) / 2)

/* Initializes the map, the higher the random range, the more hilly the terrain
 * will be. */
void map_init(map_t *m, int length, int width, int random_range);

/* Returns the height of the map in a specific point. */
int map_get_height(map_t const *m, int x, int y);

/* Set the height of the map in a specific point. */
void map_set_height(map_t *m, int x, int y, int value);

/* Set a height for water. */
void map_set_water_height(map_t *m, int new_height);

/* Run the square diamond algorithm on the map to generate a terrain. */
void map_square_diamond(map_t *m);

/* Save the map as a png image. */
void map_save_as_png(map_t const *m, char const *filename);

#endif
