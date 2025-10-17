#include "../../includes/cub3d.h"


int parse_texture(char *path, char **texture_ptr, t_data *data)
{
    int     fd;
    char    *trimmed;
    
    // 检查是否已经设置过
    if (*texture_ptr != NULL)
        return (error_msg("Duplicate texture definition"));
    
    // 去掉前后空格
    trimmed = ft_strtrim(path, " \t\n");
    
    // 检查文件是否存在
    fd = open(trimmed, O_RDONLY);
    if (fd < 0)
    {
        free(trimmed);
        return (error_msg("Texture file does not exist"));
    }
    close(fd);
    
    // 检查文件扩展名（.xpm）
    if (!check_file_extension(trimmed, ".xpm"))
    {
        free(trimmed);
        return (error_msg("Texture must be .xpm format"));
    }
    
    *texture_ptr = trimmed;
    data->tex_count++;
    return (1);
}