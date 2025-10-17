#include "../../includes/cub3d.h"

/*
 * put_pixel - Write pixel to image buffer
 * @game: Main game structure
 * @x: X coordinate
 * @y: Y coordinate
 * @color: RGB color value
 * 
 * Directly writes a pixel to the MLX image buffer for fast rendering.
 */
void put_pixel(t_game *game, int x, int y, int color)
{
    char *dst;
    
    // Calculate memory offset for this pixel
    dst = game->img.addr + (y * game->img.line_length + 
                            x * (game->img.bits_per_pixel / 8));
    // Write color value
    *(unsigned int*)dst = color;
}

/*
 * get_texture_color - Get color from texture at coordinates
 * @tex_addr: Texture data address
 * @x: Texture X coordinate
 * @y: Texture Y coordinate
 * @game: Game structure with texture info
 * 
 * Retrieves the color value at specified texture coordinates.
 */
int get_texture_color(char *tex_addr, int x, int y, t_game *game)
{
    char *pixel;
    
    // Ensure coordinates are within bounds
    if (x < 0 || x >= game->tex.width || y < 0 || y >= game->tex.height)
        return (0);
    
    // Calculate pixel position in texture data
    pixel = tex_addr + (y * game->tex.line_len + x * (game->tex.bpp / 8));
    
    // Return color as integer
    return (*(int *)pixel);
}