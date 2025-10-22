/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:09:50 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:09:51 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_texture(char *path, char **texture_ptr, t_data *data)
{
	int		fd;
	char	*trimmed;

	if (*texture_ptr != NULL)
		return (error_msg("Duplicate texture definition"));
	trimmed = ft_strtrim(path, " \t\n");
	fd = open(trimmed, O_RDONLY);
	if (fd < 0)
	{
		free(trimmed);
		return (error_msg("Texture file does not exist"));
	}
	close(fd);
	if (!check_file_extension(trimmed, ".xpm"))
	{
		free(trimmed);
		return (error_msg("Texture must be .xpm format"));
	}
	*texture_ptr = trimmed;
	data->tex_count++;
	return (1);
}
