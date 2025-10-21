#include "../../includes/cub3d.h"

void	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, 
						   game->img.img, 0, 0);
}

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (game->data.colors.ceiling_r << 16) | 
					(game->data.colors.ceiling_g << 8) | 
					game->data.colors.ceiling_b;
	floor_color = (game->data.colors.floor_r << 16) | 
				  (game->data.colors.floor_g << 8) | 
				  game->data.colors.floor_b;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel(game, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel(game, x, y, floor_color);
			x++;
		}
		y++;
	}
}