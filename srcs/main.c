#include "../includes/cub3d.h"

/*
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * 
 * Validates arguments, initializes the game, sets up event hooks,
 * and starts the main game loop.
 */
int main(int argc, char **argv)
{
    t_game game;
    
    // Validate command line arguments
    if (argc != 2)
    {
        error_msg("Usage: ./cub3D <map.cub>");
        return (1);
    }
    
    // Initialize game (parse map, init MLX, setup player)
    if (!init_game(&game, argv[1]))
    {
        error_msg("Failed to initialize game");
        return (1);
    }
    
    // Set up input hooks (keyboard, mouse, window events)
    setup_hooks(&game);
    
    // Start main game loop
    mlx_loop(game.mlx);
    
    return (0);
}