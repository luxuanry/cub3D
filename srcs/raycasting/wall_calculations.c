#include "../../includes/cub3d.h"

/*
 * calculate_wall_distance - Calculate perpendicular distance to wall
 * @ray: Ray structure containing DDA results
 * @posX: Player X position
 * @posY: Player Y position
 * 
 * Calculates the perpendicular distance from the player to the wall.
 * Using perpendicular distance (not Euclidean) prevents fisheye effect.
 */
void calculate_wall_distance(t_ray *ray, double posX, double posY)
{
	// Calculate perpendicular distance to avoid fisheye effect
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - posX + 
							(1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - posY + 
							(1 - ray->stepY) / 2) / ray->rayDirY;
}

/*
 * calculate_wall_height - Calculate the height of the wall stripe to draw
 * @ray: Ray structure containing wall distance
 * 
 * Converts the wall distance to a screen-space wall height.
 * Closer walls appear taller, farther walls appear shorter.
 */
void calculate_wall_height(t_ray *ray)
{
	// Calculate height of line to draw on screen
	ray->lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
	
	// Calculate lowest and highest pixel to fill in current stripe
	ray->drawStart = -ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	
	ray->drawEnd = ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (ray->drawEnd >= SCREEN_HEIGHT)
		ray->drawEnd = SCREEN_HEIGHT - 1;
}