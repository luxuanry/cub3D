/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:52:58 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 12:53:01 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_direction(&game->player, x, \
			&ray.raydir_x, &ray.raydir_y);
		init_dda(&ray, game->player.pos_x, game->player.pos_y);
		perform_dda(&ray, game->data.map.grid, \
			game->data.map.height);
		calculate_wall_distance(&ray, game->player.pos_x, game->player.pos_y);
		calculate_wall_height(&ray);
		draw_textured_wall(game, &ray, x);
		x++;
	}
}

void	calculate_ray_direction(t_player *player, int x, \
	double *raydir_x, double *raydir_y)
{
	double	camerax;

	camerax = 2 * x / (double)SCREEN_WIDTH - 1;
	*raydir_x = player->dir_x + player->plane_x * camerax;
	*raydir_y = player->dir_y + player->plane_y * camerax;
}
