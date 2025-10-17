#include "../../includes/cub3d.h"

/*
 * draw_textured_wall - Draw a vertical stripe of textured wall
 * @game: Main game structure
 * @ray: Ray information including wall height
 * @x: Screen column to draw
 * 
 * Renders one vertical line of the wall with proper texture mapping.
 */
void draw_textured_wall(t_game *game, t_ray *ray, int x)
{
    char    *tex_addr;
    int     texX;
    int     y;
    int     texY;
    int     color;
    double  step;
    double  texPos;
    
    // Select appropriate texture based on wall direction (pass game, not textures!)
    tex_addr = select_wall_texture(ray, game);
    
    // Calculate texture X coordinate
    texX = calculate_texture_x(ray, game->player.posX, 
                               game->player.posY, game->tex.width);
    
    // Calculate step size for texture Y coordinate
    step = 1.0 * game->tex.height / ray->lineHeight;
    
    // Starting texture position (with offset for wall portions off-screen)
    texPos = (ray->drawStart - SCREEN_HEIGHT / 2 + 
              ray->lineHeight / 2) * step;
    
    // Draw each pixel of the wall stripe
    y = ray->drawStart;
    while (y < ray->drawEnd)
    {
        // Calculate texture Y coordinate
        texY = (int)texPos & (game->tex.height - 1);
        texPos += step;
        
        // Get color from texture (pass game as 4th argument!)
        color = get_texture_color(tex_addr, texX, texY, game);
        
        // Make Y-side walls darker for depth perception
        if (ray->side == 1)
            color = (color >> 1) & 8355711; // Darken color by 50%
        
        // Draw pixel to screen buffer
        put_pixel(game, x, y, color);
        y++;
    }
}