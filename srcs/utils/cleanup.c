#include "../../includes/cub3d.h"

int	close_game(t_game *game)
{
	free_textures(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_data(&game->data);
	exit(0);
	return (0);
}

int	game_loop(t_game *game)
{
	render_frame(game);
	return (0);
}
