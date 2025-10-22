/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:09:37 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:37:00 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	add_map_line(char *line, t_data *data)
{
	char	**new_grid;
	int		i;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[--len] = '\0';
	new_grid = malloc(sizeof(char *) * (data->map.height + 1));
	if (!new_grid)
		return (error_msg("Memory allocation failed"));
	i = -1;
	while (++i < data->map.height)
		new_grid[i] = data->map.grid[i];
	new_grid[i] = ft_strdup(line);
	if (!new_grid[i])
		return (free(new_grid), error_msg("Memory allocation failed"));
	if (len > data->map.width)
		data->map.width = len;
	if (data->map.grid)
		free(data->map.grid);
	data->map.grid = new_grid;
	data->map.height++;
	return (1);
}

// int	parse_map_line(char *line, t_data *data)
// {
// 	if (data->tex_count != 4 || data->color_count != 3)
// 		return (error_msg("Map must come after textures and colors"));
// 	if (!add_map_line(line, data))
// 		return (0);
// 	return (1);
// }

int	parse_map_line(char *line, t_data *data)
{
	if (!add_map_line(line, data))
		return (0);
	return (1);
}

int	parse_file(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	init_data(data);
	if (!check_file_extension(filename, ".cub"))
		return (error_msg("file must be .cub format"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("cannot open file"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!parse_line(line, data))
			return (free(line), close(fd), get_next_line(-1), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	if (!validate_data(data))
		return (0);
	return (1);
}
