#include "../../includes/cub3d.h"

/*
 * mouse_rotate - Rotate view based on mouse movement
 * @x: Current mouse X position
 * @y: Current mouse Y position (unused but required by MLX)
 * @game: Main game structure
 * 
 * Rotates the player's view based on horizontal mouse movement.
 * The rotation speed is proportional to mouse distance from center.
 * 
 * FPS-style mouse look: Uncomment the mlx_mouse_move call at the end
 * to re-center the mouse for continuous rotation.
 */
static void	apply_rotation(t_game *game, double rotation)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(rotation)
		- game->player.dirY * sin(rotation);
	game->player.dirY = old_dir_x * sin(rotation)
		+ game->player.dirY * cos(rotation);
	old_plane_x = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(rotation)
		- game->player.planeY * sin(rotation);
	game->player.planeY = old_plane_x * sin(rotation)
		+ game->player.planeY * cos(rotation);
}

int	mouse_rotate(int x, int y, t_game *game)
{
	double		rotation;
	static int	last_x;
	static int	first_call;

	first_call = 1;
	(void)y;
	if (first_call)
	{
		last_x = SCREEN_WIDTH / 2;
		first_call = 0;
		return (0);
	}
	if (x == last_x)
		return (0);
	rotation = -(x - last_x) * 0.0005;
	apply_rotation(game, rotation);
	last_x = SCREEN_WIDTH / 2;
	mlx_mouse_move(game->mlx, game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}

/*
 * mouse_hide - Hide the mouse cursor
 * @game: Main game structure
 * 
 * Hides the mouse cursor for immersive gameplay.
 */
void	mouse_hide(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
}

void	mouse_show(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
}
