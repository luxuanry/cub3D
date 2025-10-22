/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:10:22 by lcao              #+#    #+#             */
/*   Updated: 2025/10/22 15:10:23 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(t_game *game, char *filename)
{
	if (!parse_file(filename, &game->data))
	{
		free_data(&game->data);
		return (0);
	}
	if (!init_mlx(game))
	{
		free_data(&game->data);
		return (0);
	}
	if (!init_textures(game))
	{
		free_data(&game->data);
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	init_player(game);
	return (1);
}
