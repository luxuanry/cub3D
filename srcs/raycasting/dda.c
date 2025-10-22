/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:52:47 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 12:52:49 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda(t_ray *ray, double pos_x, double pos_y)
{
	ray->map_x = (int)pos_x;
	ray->map_y = (int)pos_y;
	ray->delta_dist_x = fabs(1 / ray->raydir_x);
	ray->delta_dist_y = fabs(1 / ray->raydir_y);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pos_x) * ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pos_y) * ray->delta_dist_y;
	}
}

static int	is_wall_hit(t_ray *ray, char **map, int height)
{
	int	row_len;

	if (ray->map_y < 0 || ray->map_y >= height || ray->map_x < 0)
		return (1);
	if (!map[ray->map_y])
		return (1);
	row_len = ft_strlen(map[ray->map_y]);
	if (ray->map_x >= row_len)
		return (1);
	if (map[ray->map_y][ray->map_x] == '1' || map[ray->map_y][ray->map_x] == ' ')
		return (1);
	return (0);
}

static void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	perform_dda(t_ray *ray, char **map, int height)
{
	int	hit;
	int	steps;

	hit = 0;
	steps = 0;
	while (!hit && steps < 100)
	{
		steps++;
		step_ray(ray);
		hit = is_wall_hit(ray, map, height);
	}
}
