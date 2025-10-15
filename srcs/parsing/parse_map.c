#include "includes/cub3d.h"


int parse_file(char *filename, t_data *data)
{
    int     fd;
    char    *line;
    
    // 1. 检查文件扩展名
    if (!check_file_extension(filename, ".cub"))
        return (error_msg("file must be .cub format"));
    
    // 2. 打开文件
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (error_msg("can not open file"));
    
    // 3. 初始化数据
    init_data(data);
    
    // 4. 逐行读取
    while (get_next_line(fd, &line) > 0)
    {
        if (!parse_line(line, data))
        {
            free(line);
            close(fd);
            return (0);
        }
        free(line);
    }
    close(fd);
    
    // 5. 验证所有信息是否完整
    if (!validate_data(data))
        return (0);
    
    return (1);
}

int parse_map_line(char *line, t_data *data)
{
    // 检查纹理和颜色是否都已设置
    if (data->tex_count != 4 || data->color_count != 3)
        return (error_msg("Map must come after textures and colors"));
    
    // 添加这行到地图
    if (!add_map_line(line, data))
        return (0);
    return (1);
}
