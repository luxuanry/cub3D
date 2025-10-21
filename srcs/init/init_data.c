#include "../../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.east = NULL;
	data->textures.west = NULL;
	data->map.grid = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.player_x = 0;
	data->map.player_y = 0;
	data->map.player_dir = 0;
	data->tex_count = 0;
	data->color_count = 0;
	data->colors.floor_r = 0;
	data->colors.floor_g = 0;
	data->colors.floor_b = 0;
	data->colors.ceiling_r = 0;
	data->colors.ceiling_g = 0;
	data->colors.ceiling_b = 0;
}

void	free_data(t_data *data)
{
	int	i;

	if (data->textures.north)
		free(data->textures.north);
	if (data->textures.south)
		free(data->textures.south);
	if (data->textures.east)
		free(data->textures.east);
	if (data->textures.west)
		free(data->textures.west);
	if (data->map.grid)
	{
		i = 0;
		while (i < data->map.height)
		{
			if (data->map.grid[i])
				free(data->map.grid[i]);
			i++;
		}
		free(data->map.grid);
	}
}
