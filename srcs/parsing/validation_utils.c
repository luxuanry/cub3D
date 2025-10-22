#include "../../includes/cub3d.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	validate_map_characters(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (!is_valid_char(data->map.grid[y][x]))
				return (error_msg("Map contains invalid character"));
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_data(t_data *data)
{
	if (data->tex_count != 4)
		return (error_msg("Missing texture definition"));
	if (data->color_count != 3)
		return (error_msg("Missing color definition"));
	if (data->map.height == 0)
		return (error_msg("No map found"));
	if (!validate_map_characters(data))
		return (0);
	if (!find_player_position(data))
		return (error_msg("Player not found or multiple players"));
	if (!check_map_walls(data))
		return (0);
	return (1);
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	find_player_position(t_data *data)
{
	int	y;
	int	x;
	int	player_count;

	y = 0;
	player_count = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (is_player_char(data->map.grid[y][x]))
			{
				player_count++;
				data->map.player_x = x;
				data->map.player_y = y;
				data->map.player_dir = data->map.grid[y][x];
				data->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (player_count == 1);
}
