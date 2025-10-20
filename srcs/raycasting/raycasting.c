#include "../../includes/cub3d.h"

/*
 * cast_rays - Main raycasting loop
 * @game: Main game structure containing all game data
 * 
 * Casts one ray per screen column to create the 3D view.
 * This is the core of the raycasting algorithm.
 */
// void cast_rays(t_game *game)
// {
//     t_ray ray;
//     int x;
    
//     // Cast one ray for each vertical stripe of the screen
//     x = 0;
//     while (x < SCREEN_WIDTH)
//     {
//         // 1. Calculate ray direction for this screen column
//         calculate_ray_direction(&game->player, x, 
//                                &ray.rayDirX, &ray.rayDirY);
        
//         // 2. Initialize DDA algorithm variables
//         init_dda(&ray, game->player.posX, game->player.posY);
        
//         // 3. Perform DDA to find wall intersection
//         perform_dda(&ray, game->data.map.grid);
        
//         // 4. Calculate perpendicular distance to wall
//         calculate_wall_distance(&ray, game->player.posX, game->player.posY);
        
//         // 5. Calculate wall height on screen
//         calculate_wall_height(&ray);
        
//         // 6. Draw the wall stripe with texture
//         draw_textured_wall(game, &ray, x);
        
//         x++;
//     }
// }

void cast_rays(t_game *game)
{
    t_ray ray;
    int x;
    
    // Cast one ray for each vertical stripe of the screen
    x = 0;
    while (x < SCREEN_WIDTH)
    {
        // 1. Calculate ray direction for this screen column
        calculate_ray_direction(&game->player, x, 
                               &ray.rayDirX, &ray.rayDirY);
        
        // 2. Initialize DDA algorithm variables
        init_dda(&ray, game->player.posX, game->player.posY);
        
        // 3. Perform DDA to find wall intersection (UPDATED - add height and width)
        perform_dda(&ray, game->data.map.grid, 
                    game->data.map.height);
        
        // 4. Calculate perpendicular distance to wall
        calculate_wall_distance(&ray, game->player.posX, game->player.posY);
        
        // 5. Calculate wall height on screen
        calculate_wall_height(&ray);
        
        // 6. Draw the wall stripe with texture
        draw_textured_wall(game, &ray, x);
        
        x++;
    }
}
/*
 * calculate_ray_direction - Calculate the ray direction for a given screen column
 * @player: Player structure containing position and direction
 * @x: Screen column (x coordinate)
 * @rayDirX: Pointer to store ray direction X component
 * @rayDirY: Pointer to store ray direction Y component
 * 
 * This converts a screen column into a ray direction in world space.
 * The camera plane is perpendicular to the direction vector.
 */
void calculate_ray_direction(t_player *player, int x, 
                             double *rayDirX, double *rayDirY)
{
    // Calculate camera X coordinate in camera space (ranges from -1 to 1)
    // x=0 gives -1, x=screenWidth gives 1
    double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
    
    // Ray direction = direction vector + plane vector * camera position
    *rayDirX = player->dirX + player->planeX * cameraX;
    *rayDirY = player->dirY + player->planeY * cameraX;
}