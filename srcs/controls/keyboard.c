/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcao <lcao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:57:02 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 15:13:47 by lcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.pos_x + game->player.dir_x * game->player.move_speed;
	move_y = game->player.pos_y + game->player.dir_y * game->player.move_speed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.pos_x = move_x;
		game->player.pos_y = move_y;
	}
}

void	move_backward(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.pos_x - game->player.dir_x * game->player.move_speed;
	move_y = game->player.pos_y - game->player.dir_y * game->player.move_speed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.pos_x = move_x;
		game->player.pos_y = move_y;
	}
}

void	move_left(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.pos_x
		- game->player.plane_x * game->player.move_speed;
	move_y = game->player.pos_y
		- game->player.plane_y * game->player.move_speed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.pos_x = move_x;
		game->player.pos_y = move_y;
	}
}

void	move_right(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.pos_x
		+ game->player.plane_x * game->player.move_speed;
	move_y = game->player.pos_y
		+ game->player.plane_y * game->player.move_speed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.pos_x = move_x;
		game->player.pos_y = move_y;
	}
}
