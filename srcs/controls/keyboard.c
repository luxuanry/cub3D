#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	double	moveX;
	double	moveY;
	
	moveX = game->player.posX + game->player.dirX * game->player.moveSpeed;
	moveY = game->player.posY + game->player.dirY * game->player.moveSpeed;
	if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
	{
		game->player.posX = moveX;
		game->player.posY = moveY;
	}
}

void move_backward(t_game *game)
{
	double	moveX;
	double	moveY;
	
	moveX = game->player.posX - game->player.dirX * game->player.moveSpeed;
	moveY = game->player.posY - game->player.dirY * game->player.moveSpeed;
	if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
	{
		game->player.posX = moveX;
		game->player.posY = moveY;
	}
}

void move_left(t_game *game)
{
	double	moveX;
	double	moveY;
	
	moveX = game->player.posX - game->player.planeX * game->player.moveSpeed;
	moveY = game->player.posY - game->player.planeY * game->player.moveSpeed;
	if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
	{
		game->player.posX = moveX;
		game->player.posY = moveY;
	}
}

void move_right(t_game *game)
{
	double	moveX;
	double	moveY;

	moveX = game->player.posX + game->player.planeX * game->player.moveSpeed;
	moveY = game->player.posY + game->player.planeY * game->player.moveSpeed;
	if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
	{
		game->player.posX = moveX;
		game->player.posY = moveY;
	}
}