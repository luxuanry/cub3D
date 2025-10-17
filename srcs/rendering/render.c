#include "../../includes/cub3d.h"

/*
 * render_frame - Render a complete frame
 * @game: Main game structure
 * 
 * Renders floor/ceiling, casts all rays, and displays the frame.
 */
void render_frame(t_game *game)
{
    // 1. Draw floor and ceiling
    draw_floor_ceiling(game);
    
    // 2. Cast rays for all walls
    cast_rays(game);
    
    // 3. Display the rendered image
    mlx_put_image_to_window(game->mlx, game->win, 
                           game->img.img, 0, 0);
}

/*
 * draw_floor_ceiling - Draw floor and ceiling colors
 * @game: Main game structure
 * 
 * Fills the top half with ceiling color and bottom half with floor color.
 */
void draw_floor_ceiling(t_game *game)
{
    int x, y;
    int ceiling_color;
    int floor_color;
    
    // Encode RGB colors into single integer
    ceiling_color = (game->data.colors.ceiling_r << 16) | 
                    (game->data.colors.ceiling_g << 8) | 
                    game->data.colors.ceiling_b;
    floor_color = (game->data.colors.floor_r << 16) | 
                  (game->data.colors.floor_g << 8) | 
                  game->data.colors.floor_b;
    
    // Draw ceiling (top half of screen)
    y = 0;
    while (y < SCREEN_HEIGHT / 2)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            put_pixel(game, x, y, ceiling_color);
            x++;
        }
        y++;
    }
    
    // Draw floor (bottom half of screen)
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            put_pixel(game, x, y, floor_color);
            x++;
        }
        y++;
    }
}