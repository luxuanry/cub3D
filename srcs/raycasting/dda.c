// #include "../../includes/cub3d.h"

// /*
//  * init_dda - Initialize DDA (Digital Differential Analysis) algorithm variables
//  * @ray: Structure containing ray and DDA information
//  * @posX: Player X position
//  * @posY: Player Y position
//  * 
//  * Sets up the initial map square and calculates the delta distances.
//  * Delta distances represent how far the ray must travel to cross one grid square.
//  */
// void init_dda(t_ray *ray, double posX, double posY)
// {
//     // Current map square the player is in
//     ray->mapX = (int)posX;
//     ray->mapY = (int)posY;
    
//     // Calculate delta distances (distance ray travels between grid lines)
//     // Using absolute value to handle both positive and negative directions
//     ray->deltaDistX = fabs(1 / ray->rayDirX);
//     ray->deltaDistY = fabs(1 / ray->rayDirY);
    
//     // Calculate step direction and initial side distances
//     if (ray->rayDirX < 0)
//     {
//         ray->stepX = -1;
//         ray->sideDistX = (posX - ray->mapX) * ray->deltaDistX;
//     }
//     else
//     {
//         ray->stepX = 1;
//         ray->sideDistX = (ray->mapX + 1.0 - posX) * ray->deltaDistX;
//     }
    
//     if (ray->rayDirY < 0)
//     {
//         ray->stepY = -1;
//         ray->sideDistY = (posY - ray->mapY) * ray->deltaDistY;
//     }
//     else
//     {
//         ray->stepY = 1;
//         ray->sideDistY = (ray->mapY + 1.0 - posY) * ray->deltaDistY;
//     }
// }

// /*
//  * perform_dda - Perform the DDA algorithm to find wall hits
//  * @ray: Ray structure with DDA variables
//  * @map: 2D map array
//  * 
//  * Steps through the grid until hitting a wall.
//  * At each step, moves to the next grid square in the direction
//  * where the ray has traveled the least distance.
//  */
// void perform_dda(t_ray *ray, char **map)
// {
//     int hit = 0;
    
//     // Keep stepping until we hit a wall
//     while (hit == 0)
//     {
//         // Jump to next map square in either X or Y direction
//         // Always jump in the direction where the ray is closest to a grid line
//         if (ray->sideDistX < ray->sideDistY)
//         {
//             ray->sideDistX += ray->deltaDistX;
//             ray->mapX += ray->stepX;
//             ray->side = 0; // X-side (vertical wall)
//         }
//         else
//         {
//             ray->sideDistY += ray->deltaDistY;
//             ray->mapY += ray->stepY;
//             ray->side = 1; // Y-side (horizontal wall)
//         }
        
//         // Check if we hit a wall ('1' in the map)
//         if (map[ray->mapY][ray->mapX] == '1')
//             hit = 1;
//     }
// }

#include "../../includes/cub3d.h"

/*
 * init_dda - Initialize DDA algorithm variables
 */
void init_dda(t_ray *ray, double posX, double posY)
{
    // Current map square the player is in
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