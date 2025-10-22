/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:09:31 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:41:48 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// int	parse_line(char *line, t_data *data)
// {
// 	char	*trimmed;

// 	if (is_empty_line(line))
// 		return (1);
// 	trimmed = line;
// 	while (*trimmed == ' ' || *trimmed == '\t')
// 		trimmed++;
// 	if (*trimmed == '\0')
// 		return (1);
// 	if (ft_strncmp(trimmed, "NO ", 3) == 0)
// 		return (parse_texture(trimmed + 3, &data->textures.north, data));
// 	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
// 		return (parse_texture(trimmed + 3, &data->textures.south, data));
// 	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
// 		return (parse_texture(trimmed + 3, &data->textures.west, data));
// 	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
// 		return (parse_texture(trimmed + 3, &data->textures.east, data));
// 	else if (ft_strncmp(trimmed, "F ", 2) == 0)
// 		return (parse_color(trimmed + 2, &data->colors, 'F', data));
// 	else if (ft_strncmp(trimmed, "C ", 2) == 0)
// 		return (parse_color(trimmed + 2, &data->colors, 'C', data));
// 	else
// 		return (parse_map_line(line, data));
// }

static int	is_config_line(char *trimmed, t_data *data)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.north, data));
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.south, data));
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.west, data));
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.east, data));
	if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (parse_color(trimmed + 2, &data->colors, 'F', data));
	if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (parse_color(trimmed + 2, &data->colors, 'C', data));
	return (0);
}

int	parse_line(char *line, t_data *data)
{
	char	*trimmed;
	int		result;

	if (is_empty_line(line))
		return (1);
	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	if (*trimmed == '\0')
		return (1);
	result = is_config_line(trimmed, data);
	if (result)
	{
		if (data->map_started)
			return (error_msg("Map must come after textures and colors"));
		return (result);
	}
	data->map_started = 1;
	return (parse_map_line(line, data));
}
