#include "includes/cub3d.h"

int parse_color(char *color_str, t_colors *colors, char type, t_data *data)
{
    char    **rgb;
    int     r, g, b;
    
    // 检查是否已经设置过
    if (type == 'F' && data->color_count & 1)
        return (error_msg("Duplicate floor color definition"));
    if (type == 'C' && data->color_count & 2)
        return (error_msg("Duplicate ceiling color definition"));
    
    // 用逗号分割字符串
    rgb = ft_split(color_str, ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
    {
        free_split(rgb);
        return (error_msg("Invalid color format, should be R,G,B"));
    }
    
    // 转换为整数
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    free_split(rgb);
    
    // 验证范围 [0, 255]
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (error_msg("RGB values must be between 0-255"));
    
    // 存储颜色
    if (type == 'F')
    {
        colors->floor_r = r;
        colors->floor_g = g;
        colors->floor_b = b;
        data->color_count |= 1;
    }
    else
    {
        colors->ceiling_r = r;
        colors->ceiling_g = g;
        colors->ceiling_b = b;
        data->color_count |= 2;
    }
    
    return (1);
}