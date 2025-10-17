#include "../../includes/cub3d.h"

/*
 * load_texture_data - Load texture and get its data address
 * @game: Main game structure
 * @path: Path to XPM file
 * @img: Pointer to store image
 * @addr: Pointer to store data address
 *
 * Returns 1 on success, 0 on failure.
 */
static int load_texture_data(t_game *game, char *path, void **img, char **addr)
{
    int width;
    int height;
    
    // Load XPM file
    *img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
    if (!*img)
        return (error_msg_prefix(path, "Failed to load texture"));
    
    // Get texture data address for pixel access
    *addr = mlx_get_data_addr(*img, &game->tex.bpp,
                              &game->tex.line_len, &game->tex.endian);
    if (!*addr)
        return (error_msg_prefix(path, "Failed to get texture data"));
    
    // Store dimensions (assuming all textures are same size)
    game->tex.width = width;
    game->tex.height = height;
    
    return (1);
}

/*
 * init_textures - Load all wall textures
 * @game: Main game structure
 *
 * Loads all four wall textures from paths in game->data.textures.
 * Returns 1 on success, 0 on failure.
 */
int init_textures(t_game *game)
{
    // Load north texture
    if (!load_texture_data(game, game->data.textures.north,
                          &game->tex.north, &game->tex.north_addr))
        return (0);
    
    // Load south texture
    if (!load_texture_data(game, game->data.textures.south,
                          &game->tex.south, &game->tex.south_addr))
        return (0);
    
    // Load west texture
    if (!load_texture_data(game, game->data.textures.west,
                          &game->tex.west, &game->tex.west_addr))
        return (0);
    
    // Load east texture
    if (!load_texture_data(game, game->data.textures.east,
                          &game->tex.east, &game->tex.east_addr))
        return (0);
    
    return (1);
}

/*
 * free_textures - Free all loaded textures
 * @game: Main game structure
 */
void free_textures(t_game *game)
{
    if (game->tex.north)
        mlx_destroy_image(game->mlx, game->tex.north);
    if (game->tex.south)
        mlx_destroy_image(game->mlx, game->tex.south);
    if (game->tex.west)
        mlx_destroy_image(game->mlx, game->tex.west);
    if (game->tex.east)
        mlx_destroy_image(game->mlx, game->tex.east);
}