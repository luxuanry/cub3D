#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
	{
		error_msg("Usage: ./cub3D maps/<map.cub>");
		return (1);
	}
	
	if (!init_game(&game, argv[1]))
	{
		error_msg("Failed to initialize game");
		return (1);
	}
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}