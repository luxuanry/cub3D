/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:56:28 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 12:56:30 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	calculate_texture_x(t_ray *ray, double pos_x, double pos_y, int texWidth)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = pos_y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = pos_x + ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texWidth);
	if (ray->side == 0 && ray->raydir_x > 0)
		tex_x = texWidth - tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		tex_x = texWidth - tex_x - 1;
	return (tex_x);
}

char	*select_wall_texture(t_ray *ray, t_game *game)
{
	if (ray->side == 1 && ray->raydir_y < 0)
		return (game->tex.north_addr);
	if (ray->side == 1 && ray->raydir_y > 0)
		return (game->tex.south_addr);
	if (ray->side == 0 && ray->raydir_x < 0)
		return (game->tex.west_addr);
	return (game->tex.east_addr);
}
