#include "../../includes/cub3d.h"

/*
 * init_mlx - Initialize MLX system
 * @game: Main game structure
 * 
 * Initializes the MLX library, creates a window, and sets up the image buffer.
 * Returns 1 on success, 0 on failure.
 */
int init_mlx(t_game *game)
{
    // Initialize MLX connection
    game->mlx = mlx_init();
    if (!game->mlx)
        return (error_msg("Failed to initialize MLX"));
    
    // Create game window
    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, 
                               SCREEN_HEIGHT, "cub3D");
    if (!game->win)
        return (error_msg("Failed to create window"));
    
    // Create image buffer for rendering
    game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img.img)
        return (error_msg("Failed to create image"));
    
    // Get direct access to image data for fast pixel manipulation
    game->img.addr = mlx_get_data_addr(game->img.img, 
                                       &game->img.bits_per_pixel,
                                       &game->img.line_length, 
                                       &game->img.endian);
    return (1);
}