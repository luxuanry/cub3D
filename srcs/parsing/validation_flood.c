/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_flood.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:09:55 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:09:56 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_adjacent_horizontal(char *row, int x, int row_len)
{
	if (x > 0 && row[x - 1] == '0')
		return (0);
	if (x < row_len - 1 && row[x + 1] == '0')
		return (0);
	return (1);
}

int	flood_fill(char **map, char **visited, int x, int y)
{
	int	row_len;

	if (y < 0 || x < 0 || !map[y])
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
	if (!flood_fill(map, visited, x - 1, y))
		return (0);
	if (!flood_fill(map, visited, x + 1, y))
		return (0);
	if (!flood_fill(map, visited, x, y - 1))
		return (0);
	if (!flood_fill(map, visited, x, y + 1))
		return (0);
	return (1);
}

static int	perform_flood_fill(t_data *data, char **visited)
{
	int	result;

	result = flood_fill(data->map.grid, visited,
			data->map.player_x, data->map.player_y);
	free_visited_array(visited, data->map.height);
	if (!result)
		return (error_msg("Map must be surrounded by walls"));
	return (1);
}

int	check_map_walls(t_data *data)
{
	char	**visited;

	if (!check_border_walls(data))
		return (error_msg("Map must be surrounded by walls"));
	if (!check_spaces_validity(data))
		return (error_msg("Invalid space inside the map"));
	visited = create_visited_array(data->map.height, data->map.width);
	if (!visited)
		return (0);
	return (perform_flood_fill(data, visited));
}
