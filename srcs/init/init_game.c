#include "../../includes/cub3d.h"

int init_game(t_game *game, char *filename)
{
	if (!parse_file(filename, &game->data))
	{
		free_data(&game->data);
		return (0);
	}
	if (!init_mlx(game))
	{
		free_data(&game->data);
		return (0);
	}
	if (!init_textures(game))
	{
		free_data(&game->data);
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	init_player(game);
	return (1);
}