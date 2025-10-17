#include "../../includes/cub3d.h"

/*
 * handle_keypress - Main keyboard event handler
 * @keycode: Key code from MLX
 * @game: Main game structure
 * 
 * Routes keyboard input to appropriate movement/rotation functions.
 * Returns 0 on success.
 */
int handle_keypress(int keycode, t_game *game)
{
    // ESC - Exit game
    if (keycode == KEY_ESC)
        close_game(game);
    
    // Movement keys
    if (keycode == KEY_W)
        move_forward(game);
    if (keycode == KEY_S)
        move_backward(game);
    if (keycode == KEY_A)
        move_left(game);
    if (keycode == KEY_D)
        move_right(game);
    
    // Rotation keys
    if (keycode == KEY_LEFT)
        rotate_left(game);
    if (keycode == KEY_RIGHT)
        rotate_right(game);
    
    // Render frame after any input
    render_frame(game);
    
    return (0);
}

/*
 * setup_hooks - Initialize all MLX hooks
 * @game: Main game structure
 * 
 * Sets up keyboard, mouse, and window event hooks.
 */
void setup_hooks(t_game *game)
{
    // Keyboard hook - on key press
    mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
    
    // Mouse movement hook (optional)
    // mlx_hook(game->win, 6, 1L<<6, mouse_rotate, game);
    
    // Window close button hook (Linux: event 17, mask 0)
    mlx_hook(game->win, 17, 0, close_game, game);
    
    // Main game loop hook
    mlx_loop_hook(game->mlx, game_loop, game);
}