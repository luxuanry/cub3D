#include "includes/cub3d.h"

int parse_line(char *line, t_data *data)
{
    // 跳过空行和只有空格的行
    if (is_empty_line(line))
        return (1);
    
    // 去掉行首空格
    while (*line == ' ' || *line == '\t')
        line++;
    
    // 判断行的类型
    if (ft_strncmp(line, "NO ", 3) == 0)
        return (parse_texture(line + 3, &data->textures.north, data));
    else if (ft_strncmp(line, "SO ", 3) == 0)
        return (parse_texture(line + 3, &data->textures.south, data));
    else if (ft_strncmp(line, "WE ", 3) == 0)
        return (parse_texture(line + 3, &data->textures.west, data));
    else if (ft_strncmp(line, "EA ", 3) == 0)
        return (parse_texture(line + 3, &data->textures.east, data));
    else if (ft_strncmp(line, "F ", 2) == 0)
        return (parse_color(line + 2, &data->colors, 'F', data));
    else if (ft_strncmp(line, "C ", 2) == 0)
        return (parse_color(line + 2, &data->colors, 'C', data));
    else if (*line == '1' || *line == ' ')
        return (parse_map_line(line, data));
    else
        return (error_msg("unknown identifier"));
}