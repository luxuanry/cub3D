#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.posX + game->player.dirX * game->player.moveSpeed;
	move_y = game->player.posY + game->player.dirY * game->player.moveSpeed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.posX = move_x;
		game->player.posY = move_y;
	}
}

void	move_backward(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.posX - game->player.dirX * game->player.moveSpeed;
	move_y = game->player.posY - game->player.dirY * game->player.moveSpeed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.posX = move_x;
		game->player.posY = move_y;
	}
}

void	move_left(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.posX - game->player.planeX * game->player.moveSpeed;
	move_y = game->player.posY - game->player.planeY * game->player.moveSpeed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.posX = move_x;
		game->player.posY = move_y;
	}
}

void	move_right(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->player.posX + game->player.planeX * game->player.moveSpeed;
	move_y = game->player.posY + game->player.planeY * game->player.moveSpeed;
	if (game->data.map.grid[(int)move_y][(int)move_x] == '0')
	{
		game->player.posX = move_x;
		game->player.posY = move_y;
	}
}
