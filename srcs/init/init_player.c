#include "../../includes/cub3d.h"

static void	set_player_direction_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	set_player_direction_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	set_player_direction_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	set_player_direction_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	init_player(t_game *game)
{
	game->player.pos_x = game->data.map.player_x + 0.5;
	game->player.pos_y = game->data.map.player_y + 0.5;
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.03;
	if (game->data.map.player_dir == 'N')
		set_player_direction_north(&game->player);
	else if (game->data.map.player_dir == 'S')
		set_player_direction_south(&game->player);
	else if (game->data.map.player_dir == 'E')
		set_player_direction_east(&game->player);
	else if (game->data.map.player_dir == 'W')
		set_player_direction_west(&game->player);
}
