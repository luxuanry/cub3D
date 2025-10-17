#include "../../includes/cub3d.h"

int init_game(t_game *game, char *filename)
{
    // 1. Parse the configuration file and map
    if (!parse_file(filename, &game->data))
    {
        free_data(&game->data);
        return (0);
    }
    
    // 2. Initialize MLX windowing system
    if (!init_mlx(game))
    {
        free_data(&game->data);
        return (0);
    }
    
    // 3. Load textures (ADD THIS)
    if (!init_textures(game))
    {
        free_data(&game->data);
        mlx_destroy_window(game->mlx, game->win);
        return (0);
    }
    
    // 4. Initialize player position and direction
    init_player(game);
    
    return (1);
}