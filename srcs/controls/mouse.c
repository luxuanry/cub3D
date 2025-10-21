#include "../../includes/cub3d.h"

/*
 * mouse_rotate - Rotate view based on mouse movement
 * @x: Current mouse X position
 * @y: Current mouse Y position (unused but required by MLX)
 * @game: Main game structure
 * 
 * Rotates the player's view based on horizontal mouse movement.
 * The rotation speed is proportional to mouse distance from center.
 */
int mouse_rotate(int x, int y, t_game *game)
{
	double rotation;
	double oldDirX;
	double oldPlaneX;
	int center_x;
	
	(void)y; // Unused parameter
	
	center_x = SCREEN_WIDTH / 2;
	
	// Calculate rotation based on distance from screen center
	// Positive = mouse right of center = rotate right
	// Negative = mouse left of center = rotate left
	rotation = (x - center_x) * 0.001; // Sensitivity factor
	
	// Only rotate if mouse moved significantly from center
	if (rotation > 0.001 || rotation < -0.001)
	{
		// Rotate direction vector
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(rotation) - 
							game->player.dirY * sin(rotation);
		game->player.dirY = oldDirX * sin(rotation) + 
							game->player.dirY * cos(rotation);
		
		// Rotate camera plane
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(rotation) - 
							  game->player.planeY * sin(rotation);
		game->player.planeY = oldPlaneX * sin(rotation) + 
							  game->player.planeY * cos(rotation);
		
		// Re-center mouse (optional, for FPS-style mouse look)
		// mlx_mouse_move(game->mlx, game->win, center_x, SCREEN_HEIGHT / 2);
	}
	
	return (0);
}

/*
 * mouse_hide - Hide the mouse cursor
 * @game: Main game structure
 * 
 * Hides the mouse cursor for immersive gameplay.
 */
void mouse_hide(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
}

/*
 * mouse_show - Show the mouse cursor
 * @game: Main game structure
 * 
 * Shows the mouse cursor (useful for menus or pausing).
 */
void mouse_show(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
}