#include "../../includes/cub3d.h"

/*
 * close_game - Clean up resources and exit
 * @game: Main game structure
 * 
 * Frees all allocated memory, destroys MLX resources, and exits the program.
 * Returns 0 (though it exits before returning).
 */
int close_game(t_game *game)
{
    // Free textures
    free_textures(game);
    
    // Destroy image buffer
    if (game->img.img)
        mlx_destroy_image(game->mlx, game->img.img);
    
    // Destroy window
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    // Free game data
    free_data(&game->data);
    
    // Free GNL static buffer - call with invalid fd and NULL to trigger cleanup
    char *temp;
    temp = get_next_line(-1);
    if (temp)
        free(temp);
    
    exit(0);
    return (0);
}

/*
 * game_loop - Main game loop
 * @game: Main game structure
 */
int game_loop(t_game *game)
{
    render_frame(game);
    return (0);
}