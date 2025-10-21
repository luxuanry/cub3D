#include "../../includes/cub3d.h"

int init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("Failed to initialize MLX"));
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, 
							   SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		return (error_msg("Failed to create window"));
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		return (error_msg("Failed to create image"));
	game->img.addr = mlx_get_data_addr(game->img.img, 
									   &game->img.bits_per_pixel,
									   &game->img.line_length, 
									   &game->img.endian);
	return (1);
}