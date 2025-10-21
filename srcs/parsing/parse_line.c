#include "../../includes/cub3d.h"

int parse_line(char *line, t_data *data)
{
	char *trimmed;
	
	if (is_empty_line(line))
		return (1);
	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	if (*trimmed == '\0')
		return (1);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.north, data));
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.south, data));
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.west, data));
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (parse_texture(trimmed + 3, &data->textures.east, data));
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (parse_color(trimmed + 2, &data->colors, 'F', data));
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (parse_color(trimmed + 2, &data->colors, 'C', data));
	else
		return (parse_map_line(line, data));
}