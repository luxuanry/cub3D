#include "../../includes/cub3d.h"

/*
 * rotate_left - Rotate player view left
 * @game: Main game structure
 * 
 * Rotates both the direction vector and camera plane to the left.
 * Uses rotation matrix to maintain perpendicularity.
 */
void rotate_left(t_game *game)
{
    double oldDirX;
    double oldPlaneX;
    double rotSpeed;
    
    rotSpeed = -game->player.rotSpeed;  // CHANGED: Negative for left
    
    // Rotate direction vector
    oldDirX = game->player.dirX;
    game->player.dirX = game->player.dirX * cos(rotSpeed) - 
                        game->player.dirY * sin(rotSpeed);
    game->player.dirY = oldDirX * sin(rotSpeed) + 
                        game->player.dirY * cos(rotSpeed);
    
    // Rotate camera plane vector (must stay perpendicular to direction)
    oldPlaneX = game->player.planeX;
    game->player.planeX = game->player.planeX * cos(rotSpeed) - 
                          game->player.planeY * sin(rotSpeed);
    game->player.planeY = oldPlaneX * sin(rotSpeed) + 
                          game->player.planeY * cos(rotSpeed);
}

/*
 * rotate_right - Rotate player view right
 * @game: Main game structure
 * 
 * Rotates both the direction vector and camera plane to the right.
 * Uses rotation matrix with positive angle.
 */
void rotate_right(t_game *game)
{
    double oldDirX;
    double oldPlaneX;
    double rotSpeed;
    
    rotSpeed = game->player.rotSpeed;  // CHANGED: Positive for right
    
    // Rotate direction vector
    oldDirX = game->player.dirX;
    game->player.dirX = game->player.dirX * cos(rotSpeed) - 
                        game->player.dirY * sin(rotSpeed);
    game->player.dirY = oldDirX * sin(rotSpeed) + 
                        game->player.dirY * cos(rotSpeed);
    
    // Rotate camera plane vector (must stay perpendicular to direction)
    oldPlaneX = game->player.planeX;
    game->player.planeX = game->player.planeX * cos(rotSpeed) - 
                          game->player.planeY * sin(rotSpeed);
    game->player.planeY = oldPlaneX * sin(rotSpeed) + 
                          game->player.planeY * cos(rotSpeed);
}