#include "../../includes/cub3d.h"

// void clear_image(t_game *game)
// {
//     int i;
//     int total_pixels;
//     int *buffer;
//     int ceiling_color;
    
//     // Use ceiling color instead of black
//     ceiling_color = (game->data.colors.ceiling_r << 16) |
//                     (game->data.colors.ceiling_g << 8) |
//                     game->data.colors.ceiling_b;
    
//     buffer = (int *)game->img.addr;
//     total_pixels = SCREEN_WIDTH * SCREEN_HEIGHT;
//     i = 0;
//     while (i < total_pixels)
//     {
//         buffer[i] = ceiling_color;  // Use actual ceiling color
//         i++;
//     }
// }
/*
 * render_frame - Render a complete frame
 * @game: Main game structure
 * 
 * Renders floor/ceiling, casts all rays, and displays the frame.
 */
void render_frame(t_game *game)
{
	//clear_image(game);
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