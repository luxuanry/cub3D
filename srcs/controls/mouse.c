/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:57:16 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 15:21:38 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 * mouse_rotate - Rotate view based on mouse movement
 * @x: Current mouse X position
 * @y: Current mouse Y position (unused but required by MLX)
 * @game: Main game structure
 * 
 * Rotates the player's view based on horizontal mouse movement.
 * The rotation speed is proportional to mouse distance from center.
 * 
 * FPS-style mouse look: Uncomment the mlx_mouse_move call at the end
 * to re-center the mouse for continuous rotation.
 */
static void	apply_rotation(t_game *game, double rotation)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotation)
		- game->player.dir_y * sin(rotation);
	game->player.dir_y = old_dir_x * sin(rotation)
		+ game->player.dir_y * cos(rotation);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotation)
		- game->player.plane_y * sin(rotation);
	game->player.plane_y = old_plane_x * sin(rotation)
		+ game->player.plane_y * cos(rotation);
}

int	mouse_rotate(int x, int y, t_game *game)
{
	double		rotation;
	static int	last_x;
	static int	first_call;

	first_call = 1;
	(void)y;
	if (first_call)
	{
		last_x = SCREEN_WIDTH / 2;
		first_call = 0;
		return (0);
	}
	if (x == last_x)
		return (0);
	rotation = -(x - last_x) * 0.0005;
	apply_rotation(game, rotation);
	last_x = x;
	return (0);
}

void	mouse_hide(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
}

void	mouse_show(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
}
