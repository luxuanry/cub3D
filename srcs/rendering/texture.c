#include "../../includes/cub3d.h"

/*
 * calculate_texture_x - Calculate which X coordinate on the texture to use
 */
int calculate_texture_x(t_ray *ray, double posX, double posY, int texWidth)
{
	double wallX;
	int texX;
	
	if (ray->side == 0)
		wallX = posY + ray->perpWallDist * ray->rayDirY;
	else
		wallX = posX + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);
	
	texX = (int)(wallX * (double)texWidth);
	
	if (ray->side == 0 && ray->rayDirX > 0)
		texX = texWidth - texX - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		texX = texWidth - texX - 1;
	
	return (texX);
}

/*
 * select_wall_texture - Determine which texture to use
 */
char *select_wall_texture(t_ray *ray, t_game *game)
{
	if (ray->side == 1 && ray->rayDirY < 0)
		return (game->tex.north_addr);
	if (ray->side == 1 && ray->rayDirY > 0)
		return (game->tex.south_addr);
	if (ray->side == 0 && ray->rayDirX < 0)
		return (game->tex.west_addr);
	return (game->tex.east_addr);
}