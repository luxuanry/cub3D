#include "../../includes/cub3d.h"

int	mouse_rotate(int x, int y, t_game *game)
{
	double rotation;
	double oldDirX;
	double oldPlaneX;
	static int last_x = -1;
	static int init = 0;
	
	(void)y;
	
	// Initialize last_x on first call
	if (!init)
	{
		last_x = x;
		init = 1;
		return (0);
	}
	
	// Calculate rotation based on mouse movement delta
	// Using the difference from last position for smoother control
	// Negative to invert direction: mouse right = rotate right
	rotation = -(x - last_x) * 0.0005; // Lower sensitivity (was 0.001-0.002)
	
	// Only rotate if mouse moved
	if (rotation > 0.00001 || rotation < -0.00001)
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
	}
	
	last_x = x;
	
	// FPS-style mouse re-centering for continuous rotation
	// Re-center mouse after each movement so you can rotate infinitely
	mlx_mouse_move(game->mlx, game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	last_x = SCREEN_WIDTH / 2; // Reset last_x to center after re-centering
	
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