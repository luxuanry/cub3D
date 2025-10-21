#include "../../includes/cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dirx;
	double	old_planex;
	double	rotspeed;

	rotspeed = -game->player.rotSpeed;
	old_dirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(rotspeed)
		- game->player.dirY * sin(rotspeed);
	game->player.dirY = old_dirx * sin(rotspeed)
		+ game->player.dirY * cos(rotspeed);
	old_planex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(rotspeed)
		- game->player.planeY * sin(rotspeed);
	game->player.planeY = old_planex * sin(rotspeed)
		+ game->player.planeY * cos(rotspeed);
}

void	rotate_right(t_game *game)
{
	double	old_dirx;
	double	old_planex;
	double	rotspeed;

	rotspeed = game->player.rotSpeed;
	old_dirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(rotspeed)
		- game->player.dirY * sin(rotspeed);
	game->player.dirY = old_dirx * sin(rotspeed)
		+ game->player.dirY * cos(rotspeed);
	old_planex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(rotspeed)
		- game->player.planeY * sin(rotspeed);
	game->player.planeY = old_planex * sin(rotspeed)
		+ game->player.planeY * cos(rotspeed);
}
