#include "../../includes/cub3d.h"

int	add_map_line(char *line, t_data *data)
{
	char	**new_grid;
	int		i;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	new_grid = malloc(sizeof(char *) * (data->map.height + 1));
	if (!new_grid)
		return (error_msg("Memory allocation failed"));
	i = 0;
	while (i < data->map.height)
	{
		new_grid[i] = data->map.grid[i];
		i++;
	}
	new_grid[i] = ft_strdup(line);
	if (!new_grid[i])
	{
		free(new_grid);
		return (error_msg("Memory allocation failed"));
	}
	len = ft_strlen(line);
	if (len > data->map.width)
		data->map.width = len;
	if (data->map.grid)
		free(data->map.grid);
	data->map.grid = new_grid;
	data->map.height++;
	return (1);
}

int	parse_map_line(char *line, t_data *data)
{
	if (data->tex_count != 4 || data->color_count != 3)
		return (error_msg("Map must come after textures and colors"));
	if (!add_map_line(line, data))
		return (0);
	return (1);
}

int parse_file(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	init_data(data);
	if (!check_file_extension(filename, ".cub"))
		return (error_msg("file must be .cub format"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("cannot open file"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!parse_line(line, data))
		{
			free(line);
			close(fd);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	if (!validate_data(data))
		return (0);
	return (1);
}
