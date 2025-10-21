#include "../../includes/cub3d.h"

static void	set_player_direction_north(t_player *player)
{
	player->dirX = 0;
	player->dirY = -1;
	player->planeX = 0.66;
	player->planeY = 0;
}

static void	set_player_direction_south(t_player *player)
{
	player->dirX = 0;
	player->dirY = 1;
	player->planeX = -0.66;
	player->planeY = 0;
}

static void	set_player_direction_east(t_player *player)
{
	player->dirX = 1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
}

static void	set_player_direction_west(t_player *player)
{
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = -0.66;
}

void	init_player(t_game *game)
{
	game->player.posX = game->data.map.player_x + 0.5;
	game->player.posY = game->data.map.player_y + 0.5;
	game->player.moveSpeed = 0.05;
	game->player.rotSpeed = 0.03;
	if (game->data.map.player_dir == 'N')
		set_player_direction_north(&game->player);
	else if (game->data.map.player_dir == 'S')
		set_player_direction_south(&game->player);
	else if (game->data.map.player_dir == 'E')
		set_player_direction_east(&game->player);
	else if (game->data.map.player_dir == 'W')
		set_player_direction_west(&game->player);
}
