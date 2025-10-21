#include "../../includes/cub3d.h"

static int	check_duplicate(char type, t_data *data)
{
	if (type == 'F' && data->color_count & 1)
		return (error_msg("Duplicate floor color definition"));
	if (type == 'C' && data->color_count & 2)
		return (error_msg("Duplicate ceiling color definition"));
	return (1);
}

static int	validate_rgb(char **rgb)
{
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (0);
	return (1);
}

static int	check_rgb_range(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (1);
}

static void	store_color(t_colors *colors, char type, int rgb[3], t_data *data)
{
	if (type == 'F')
	{
		colors->floor_r = rgb[0];
		colors->floor_g = rgb[1];
		colors->floor_b = rgb[2];
		data->color_count |= 1;
	}
	else
	{
		colors->ceiling_r = rgb[0];
		colors->ceiling_g = rgb[1];
		colors->ceiling_b = rgb[2];
		data->color_count |= 2;
	}
}

int	parse_color(char *color_str, t_colors *colors, char type, t_data *data)
{
	char	**split;
	int		rgb[3];

	if (!check_duplicate(type, data))
		return (0);
	split = ft_split(color_str, ',');
	if (!validate_rgb(split))
	{
		free_split(split);
		return (error_msg("Invalid color format, should be R,G,B"));
	}
	rgb[0] = ft_atoi(split[0]);
	rgb[1] = ft_atoi(split[1]);
	rgb[2] = ft_atoi(split[2]);
	free_split(split);
	if (!check_rgb_range(rgb[0], rgb[1], rgb[2]))
		return (error_msg("RGB values must be between 0-255"));
	store_color(colors, type, rgb, data);
	return (1);
}
