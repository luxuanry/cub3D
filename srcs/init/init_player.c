#include "../../includes/cub3d.h"

/*
 * set_player_direction_north - Set player facing north
 * @player: Player structure
 */
static void set_player_direction_north(t_player *player)
{
    player->dirX = 0;
    player->dirY = -1;
    player->planeX = 0.66;  // FOV ~66 degrees
    player->planeY = 0;
}

/*
 * set_player_direction_south - Set player facing south
 * @player: Player structure
 */
static void set_player_direction_south(t_player *player)
{
    player->dirX = 0;
    player->dirY = 1;
    player->planeX = -0.66;
    player->planeY = 0;
}

/*
 * set_player_direction_east - Set player facing east
 * @player: Player structure
 */
static void set_player_direction_east(t_player *player)
{
    player->dirX = 1;
    player->dirY = 0;
    player->planeX = 0;
    player->planeY = 0.66;
}

/*
 * set_player_direction_west - Set player facing west
 * @player: Player structure
 */
static void set_player_direction_west(t_player *player)
{
    player->dirX = -1;
    player->dirY = 0;
    player->planeX = 0;
    player->planeY = -0.66;
}

/*
 * init_player - Initialize player position and direction
 * @game: Main game structure
 * 
 * Sets up the player's starting position, direction vector, and camera plane
 * based on the player's starting orientation (N/S/E/W) found in the map.
 */
void init_player(t_game *game)
{
    // Set player position to center of starting grid square
    game->player.posX = game->data.map.player_x + 0.5;
    game->player.posY = game->data.map.player_y + 0.5;
    
    // Set movement and rotation speeds
    game->player.moveSpeed = 0.05;
    game->player.rotSpeed = 0.03;
    
    // Set direction and camera plane based on starting orientation
    if (game->data.map.player_dir == 'N')
        set_player_direction_north(&game->player);
    else if (game->data.map.player_dir == 'S')
        set_player_direction_south(&game->player);
    else if (game->data.map.player_dir == 'E')
        set_player_direction_east(&game->player);
    else if (game->data.map.player_dir == 'W')
        set_player_direction_west(&game->player);
}