#include "../../includes/cub3d.h"

int	flood_fill(char **map, char **visited, int x, int y, int width, int height)
{
	int	row_len;
	
	if (y < 0 || y >= height || x < 0)
		return (1);   
	if (!map[y])
		return (1);    
	row_len = ft_strlen(map[y]);   
	if (x >= row_len)
		return (1);    
	if (map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1')
		return (1);
	if (visited[y][x])
		return (1);
	visited[y][x] = 1;
	if (!flood_fill(map, visited, x - 1, y, width, height))
		return (0);
	if (!flood_fill(map, visited, x + 1, y, width, height))
		return (0);
	if (!flood_fill(map, visited, x, y - 1, width, height))
		return (0);
	if (!flood_fill(map, visited, x, y + 1, width, height))
		return (0);
	return (1);
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
			if (data->map.grid[y][x] != '0' && 
				data->map.grid[y][x] != '1' &&
				data->map.grid[y][x] != ' ' &&
				data->map.grid[y][x] != 'N' &&
				data->map.grid[y][x] != 'S' &&
				data->map.grid[y][x] != 'E' &&
				data->map.grid[y][x] != 'W')
			{
				return (error_msg("Map contains invalid character"));
			}
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
			if (data->map.grid[y][x] == 'N' || 
				data->map.grid[y][x] == 'S' ||
				data->map.grid[y][x] == 'E' || 
				data->map.grid[y][x] == 'W')
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

int	check_border_walls(t_data *data)
{
	int	y;
	int	x;
	int	row_len;
	
	y = 0;
	while (y < data->map.height)
	{
		if (y == 0 || y == data->map.height - 1)
		{
			x = 0;
			row_len = ft_strlen(data->map.grid[y]);
			while (x < row_len)
			{
				if (data->map.grid[y][x] == '0')
					return (0);
				x++;
			}
		}
		else
		{
			row_len = ft_strlen(data->map.grid[y]);
			x = 0;
			while (x < row_len && data->map.grid[y][x] == ' ')
				x++;
			if (x < row_len && data->map.grid[y][x] != '1')
				return (0);
			x = row_len - 1;
			while (x >= 0 && data->map.grid[y][x] == ' ')
				x--;
			if (x >= 0 && data->map.grid[y][x] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}

int check_spaces_validity(t_data *data)
{
	int	x;
	int	y;
	int	row_len;
	int	up_len;
	int	down_len;
	
	y = 0;
	while (y < data->map.height)
	{
		row_len = ft_strlen(data->map.grid[y]);
		x = 0;
		while (x < row_len)
		{
			if (data->map.grid[y][x] == ' ')
			{
				if (y > 0)
				{
					up_len = ft_strlen(data->map.grid[y - 1]);
					if (x < up_len && data->map.grid[y - 1][x] == '0')
						return (0);
				}
				if (y < data->map.height - 1)
				{
					down_len = ft_strlen(data->map.grid[y + 1]);
					if (x < down_len && data->map.grid[y + 1][x] == '0')
						return (0);
				}
				if (x > 0 && data->map.grid[y][x - 1] == '0')
					return (0);
				if (x < row_len - 1 && data->map.grid[y][x + 1] == '0')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int check_map_walls(t_data *data)
{
	char    **visited;
	int     result;
	
	if (!check_border_walls(data))
		return (error_msg("Map must be surrounded by walls"));
	if (!check_spaces_validity(data))
		return (error_msg("Invalid space inside the map"));
	visited = create_visited_array(data->map.height, data->map.width);
	if (!visited)
		return (0);
	result = flood_fill(data->map.grid, visited, 
						data->map.player_x, data->map.player_y,
						data->map.width, data->map.height);
	free_visited_array(visited, data->map.height);
	if (!result)
		return (error_msg("Map must be surrounded by walls")); 
	return (1);
}