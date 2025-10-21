#include "../../includes/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length
			+ x * (game->img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_texture_color(char *tex_addr, int x, int y, t_game *game)
{
	char	*pixel;

	if (x < 0 || x >= game->tex.width || y < 0 || y >= game->tex.height)
		return (0);
	pixel = tex_addr + (y * game->tex.line_len + x * (game->tex.bpp / 8));
	return (*(int *)pixel);
}
