/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:53:30 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 12:54:31 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_adjusted_tex_y(double tex_pos, int tex_height)
{
	int	tex_y;

	tex_y = (int)tex_pos % tex_height;
	if (tex_y < 0)
		tex_y += tex_height;
	return (tex_y);
}

static void	draw_column_pixels(t_game *game, t_ray *ray, char *tex_addr, int x)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	step = 1.0 * game->tex.height / ray->line_height;
	tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = get_adjusted_tex_y(tex_pos, game->tex.height);
		tex_pos += step;
		color = get_texture_color(tex_addr, \
			calculate_texture_x(ray, game->player.pos_x, \
			game->player.pos_y, game->tex.width), tex_y, game);
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	char	*tex_addr;

	tex_addr = select_wall_texture(ray, game);
	draw_column_pixels(game, ray, tex_addr, x);
}
