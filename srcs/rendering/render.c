/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:56:18 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 12:56:20 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img.img, 0, 0);
}

static int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	draw_horizontal_line(t_game *game, int y, int color)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		put_pixel(game, x, y, color);
		x++;
	}
}

void	draw_floor_ceiling(t_game *game)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = get_color(game->data.colors.ceiling_r,
			game->data.colors.ceiling_g, game->data.colors.ceiling_b);
	floor_color = get_color(game->data.colors.floor_r,
			game->data.colors.floor_g, game->data.colors.floor_b);
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
		draw_horizontal_line(game, y++, ceiling_color);
	while (y < SCREEN_HEIGHT)
		draw_horizontal_line(game, y++, floor_color);
}
