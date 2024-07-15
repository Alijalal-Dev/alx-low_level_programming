#include "main.h"

/**
 * free_grid - frees a 2 dimensional array
 * @grid: pointer to a 2 dimensional array
 * @height: array height
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
