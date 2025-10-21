#include "../../includes/cub3d.h"


int parse_texture(char *path, char **texture_ptr, t_data *data)
{
	int     fd;
	char    *trimmed;

	if (*texture_ptr != NULL)
		return (error_msg("Duplicate texture definition"));
	trimmed = ft_strtrim(path, " \t\n");
	fd = open(trimmed, O_RDONLY);
	if (fd < 0)
	{
		free(trimmed);
		return (error_msg("Texture file does not exist"));
	}
	close(fd);
	if (!check_file_extension(trimmed, ".xpm"))
	{
		free(trimmed);
		return (error_msg("Texture must be .xpm format"));
	}
	
	*texture_ptr = trimmed;
	data->tex_count++;
	return (1);
}