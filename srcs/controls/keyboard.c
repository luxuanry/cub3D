#include "../../includes/cub3d.h"

/*
 * move_forward - Move player forward
 * @game: Main game structure
 * 
 * Moves the player forward in the direction they're facing,
 * with collision detection against walls.
 */
void move_forward(t_game *game)
{
    double moveX, moveY;
    
    // Calculate new position
    moveX = game->player.posX + game->player.dirX * game->player.moveSpeed;
    moveY = game->player.posY + game->player.dirY * game->player.moveSpeed;
    
    // Check collision with walls before moving
    if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
    {
        game->player.posX = moveX;
        game->player.posY = moveY;
    }
}

/*
 * move_backward - Move player backward
 * @game: Main game structure
 * 
 * Moves the player backward (opposite to facing direction),
 * with collision detection against walls.
 */
void move_backward(t_game *game)
{
    double moveX, moveY;
    
    // Calculate new position (opposite direction)
    moveX = game->player.posX - game->player.dirX * game->player.moveSpeed;
    moveY = game->player.posY - game->player.dirY * game->player.moveSpeed;
    
    // Check collision with walls before moving
    if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
    {
        game->player.posX = moveX;
        game->player.posY = moveY;
    }
}

/*
 * move_left - Strafe left
 * @game: Main game structure
 * 
 * Moves the player left (perpendicular to facing direction),
 * with collision detection against walls.
 */
void move_left(t_game *game)
{
    double moveX, moveY;
    
    // Calculate new position (use plane vector for strafing)
    moveX = game->player.posX - game->player.planeX * game->player.moveSpeed;
    moveY = game->player.posY - game->player.planeY * game->player.moveSpeed;
    
    // Check collision with walls before moving
    if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
    {
        game->player.posX = moveX;
        game->player.posY = moveY;
    }
}

/*
 * move_right - Strafe right
 * @game: Main game structure
 * 
 * Moves the player right (perpendicular to facing direction),
 * with collision detection against walls.
 */
void move_right(t_game *game)
{
    double moveX, moveY;
    
    // Calculate new position (use plane vector for strafing)
    moveX = game->player.posX + game->player.planeX * game->player.moveSpeed;
    moveY = game->player.posY + game->player.planeY * game->player.moveSpeed;
    
    // Check collision with walls before moving
    if (game->data.map.grid[(int)moveY][(int)moveX] == '0')
    {
        game->player.posX = moveX;
        game->player.posY = moveY;
    }
}