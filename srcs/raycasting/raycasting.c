#include "../../includes/cub3d.h"

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_direction(&game->player, x, 
							   &ray.rayDirX, &ray.rayDirY);
		init_dda(&ray, game->player.posX, game->player.posY);
		perform_dda(&ray, game->data.map.grid, 
					game->data.map.height);
		calculate_wall_distance(&ray, game->player.posX, game->player.posY);
		calculate_wall_height(&ray);
		draw_textured_wall(game, &ray, x);
		x++;
	}
}

void calculate_ray_direction(t_player *player, int x, 
							 double *rayDirX, double *rayDirY)
{
	double	cameraX;

	cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	*rayDirX = player->dirX + player->planeX * cameraX;
	*rayDirY = player->dirY + player->planeY * cameraX;
}