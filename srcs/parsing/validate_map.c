#include "includes/cub3d.h"

int validate_data(t_data *data)
{
    // 1. 检查纹理和颜色是否完整
    if (data->tex_count != 4)
        return (error_msg("Missing texture definition"));
    if (data->color_count != 3)
        return (error_msg("Missing color definition"));
    
    // 2. 检查地图是否存在
    if (data->map.height == 0)
        return (error_msg("No map found"));
    
    // 3. 查找玩家位置
    if (!find_player_position(data))
        return (error_msg("Player not found or multiple players"));
    
    // 4. 验证地图字符
    if (!validate_map_characters(data))
        return (0);
    
    // 5. 检查地图是否被墙包围
    if (!check_map_walls(data))
        return (error_msg("Map must be surrounded by walls"));
    
    return (1);
}
int find_player_position(t_data *data)
{
    int y, x;
    int player_count = 0;
    
    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (data->map.grid[y][x])
        {
            if (data->map.grid[y][x] == 'N' || 
                data->map.grid[y][x] == 'S' ||
                data->map.grid[y][x] == 'E' || 
                data->map.grid[y][x] == 'W')
            {
                player_count++;
                data->map.player_x = x;
                data->map.player_y = y;
                data->map.player_dir = data->map.grid[y][x];
                data->map.grid[y][x] = '0'; // 替换为空地
            }
            x++;
        }
        y++;
	}
	return (player_count == 1);
}

int validate_map_characters(t_data *data)
{
    int y, x;
    
    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (data->map.grid[y][x])
        {
            if (data->map.grid[y][x] != '0' && 
                data->map.grid[y][x] != '1' &&
                data->map.grid[y][x] != ' ')
                return (error_msg("Map contains invalid character"));
            x++;
        }
        y++;
    }
    return (1);
}

int check_map_walls(t_data *data)
{
    char    **visited;
    int     result;
    
    // 创建访问标记数组
    visited = create_visited_array(data->map.height, data->map.width);
    if (!visited)
        return (0);
    
    // 从玩家位置开始洪水填充
    result = flood_fill(data->map.grid, visited, 
                        data->map.player_x, data->map.player_y,
                        data->map.width, data->map.height);
    
    free_visited_array(visited, data->map.height);
    return (result);
}