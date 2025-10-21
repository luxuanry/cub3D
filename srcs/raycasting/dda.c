#include "../../includes/cub3d.h"

void	init_dda(t_ray *ray, double posX, double posY)
{
	ray->mapX = (int)posX;
	ray->mapY = (int)posY;
	
	// Calculate delta distances
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	
	// Calculate step direction and initial side distances
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - posX) * ray->deltaDistX;
	}
	
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - posY) * ray->deltaDistY;
	}
}

/*
 * perform_dda - Perform the DDA algorithm to find wall hits
 * @ray: Ray structure with DDA variables
 * @map: 2D map array
 * @height: Map height
 * @width: Map width
 * 
 * Steps through the grid until hitting a wall.
 */
void perform_dda(t_ray *ray, char **map, int height)
{
	int hit = 0;
	int row_len;
	int max_steps = 100;
	int steps = 0;
	
	while (hit == 0 && steps < max_steps)
	{
		steps++;
		
		// Jump to next map square
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		
		// Bounds checking
		if (ray->mapY < 0 || ray->mapY >= height || ray->mapX < 0)
		{
			hit = 1;
			continue;
		}
		
		// Check if map row exists
		if (!map[ray->mapY])
		{
			hit = 1;
			continue;
		}
		
		// Check row length
		row_len = ft_strlen(map[ray->mapY]);
		if (ray->mapX >= row_len)
		{
			hit = 1;
			continue;
		}
		
		// Check if we hit a wall or space
		if (map[ray->mapY][ray->mapX] == '1' || map[ray->mapY][ray->mapX] == ' ')
			hit = 1;
	}
}