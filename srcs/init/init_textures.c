/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:10:51 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:10:52 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_texture_data(t_game *game, char *path, void **img, char **addr)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!*img)
		return (error_msg_prefix(path, "Failed to load texture"));
	*addr = mlx_get_data_addr(*img, &game->tex.bpp,
			&game->tex.line_len, &game->tex.endian);
	if (!*addr)
		return (error_msg_prefix(path, "Failed to get texture data"));
	game->tex.width = width;
	game->tex.height = height;
	return (1);
}

int	init_textures(t_game *game)
{
	if (!load_texture_data(game, game->data.textures.north,
			&game->tex.north, &game->tex.north_addr))
		return (0);
	if (!load_texture_data(game, game->data.textures.south,
			&game->tex.south, &game->tex.south_addr))
		return (0);
	if (!load_texture_data(game, game->data.textures.west,
			&game->tex.west, &game->tex.west_addr))
		return (0);
	if (!load_texture_data(game, game->data.textures.east,
			&game->tex.east, &game->tex.east_addr))
		return (0);
	return (1);
}

void	free_textures(t_game *game)
{
	if (game->tex.north)
		mlx_destroy_image(game->mlx, game->tex.north);
	if (game->tex.south)
		mlx_destroy_image(game->mlx, game->tex.south);
	if (game->tex.west)
		mlx_destroy_image(game->mlx, game->tex.west);
	if (game->tex.east)
		mlx_destroy_image(game->mlx, game->tex.east);
}
