#include "../../includes/cub3d.h"


/*
 * flood_fill - Check if map is properly enclosed
 * @map: Map grid
 * @visited: Visited array
 * @x: Current X position
 * @y: Current Y position
 * @width: Map width
 * @height: Map height
 * 
 * Uses flood fill algorithm to check if player area is surrounded by walls.
 * Returns 1 if valid (enclosed), 0 if invalid (has leaks).
 */
// int flood_fill(char **map, char **visited, int x, int y, int width, int height)
// {
//     int row_len;
    
//     // Out of bounds check
//     if (y < 0 || y >= height || x < 0)
//         return (0);
    
//     // Check if x is beyond current row length
//     row_len = ft_strlen(map[y]);
//     if (x >= row_len)
//         return (0);
    
//     // Space or edge means leak
//     if (map[y][x] == ' ')
//         return (0);
    
//     // Wall - stop here
//     if (map[y][x] == '1')
//         return (1);
    
//     // Already visited
//     if (visited[y][x])
//         return (1);
    
//     // Mark as visited
//     visited[y][x] = 1;
    
//     // Check all 4 directions
//     if (!flood_fill(map, visited, x, y - 1, width, height))
//         return (0);
//     if (!flood_fill(map, visited, x, y + 1, width, height))
//         return (0);
//     if (!flood_fill(map, visited, x - 1, y, width, height))
//         return (0);
//     if (!flood_fill(map, visited, x + 1, y, width, height))
//         return (0);
    
//     return (1);
// }

int flood_fill(char **map, char **visited, int x, int y, int width, int height)
{
    int row_len;
    
    // Out of bounds check
    if (y < 0 || y >= height || x < 0 || x >= width)
        return (1);  // Out of map bounds = treat as wall
    
    // Safety check - make sure row exists
    if (!map[y])
        return (1);
    
    // Check current row length
    row_len = ft_strlen(map[y]);
    
    // If x is beyond this row's length, treat as wall (space)
    if (x >= row_len)
        return (1);
    
    // Space is treated as wall
    if (map[y][x] == ' ')
        return (1);
    
    // Wall - stop here
    if (map[y][x] == '1')
        return (1);
    
    // Safety check for visited array
    if (!visited[y])
        return (1);
    
    // Already visited
    if (visited[y][x])
        return (1);
    
    // Mark as visited
    visited[y][x] = 1;
    
    // Check all 4 directions recursively
    if (!flood_fill(map, visited, x, y - 1, width, height))
        return (0);
    if (!flood_fill(map, visited, x, y + 1, width, height))
        return (0);
    if (!flood_fill(map, visited, x - 1, y, width, height))
        return (0);
    if (!flood_fill(map, visited, x + 1, y, width, height))
        return (0);
    
    return (1);
}

int validate_data(t_data *data)
{
    // 1. Check textures and colors
    if (data->tex_count != 4)
        return (error_msg("Missing texture definition"));
    if (data->color_count != 3)
        return (error_msg("Missing color definition"));
    
    // 2. Check map exists
    if (data->map.height == 0)
        return (error_msg("No map found"));
    
    // 3. Find player FIRST - this replaces N/S/E/W with '0'
    if (!find_player_position(data))
        return (error_msg("Player not found or multiple players"));
    
    // 4. THEN validate characters (after N is replaced with 0)
    if (!validate_map_characters(data))
        return (0);
    
    // 5. Check walls
    if (!check_map_walls(data))
        return (error_msg("Map must be surrounded by walls"));
    
    return (1);
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
            {
                // printf("DEBUG: Invalid character '%c' (ASCII %d) at row %d, col %d\n", 
                //        data->map.grid[y][x], (int)data->map.grid[y][x], y, x);
                return (error_msg("Map contains invalid character"));
            }
            x++;
        }
        y++;
    }
    return (1);
}

int find_player_position(t_data *data)
{
    int y, x;
    int player_count = 0;
    
    // printf("DEBUG: Map height = %d\n", data->map.height);
    y = 0;
    while (y < data->map.height)
    {
        // printf("DEBUG: Row %d: [%s]\n", y, data->map.grid[y]);
        x = 0;
        while (data->map.grid[y][x])
        {
            if (data->map.grid[y][x] == 'N' || 
                data->map.grid[y][x] == 'S' ||
                data->map.grid[y][x] == 'E' || 
                data->map.grid[y][x] == 'W')
            {
                // printf("DEBUG: Found player '%c' at (%d, %d)\n", 
                //        data->map.grid[y][x], x, y);
                player_count++;
                data->map.player_x = x;
                data->map.player_y = y;
                data->map.player_dir = data->map.grid[y][x];
                data->map.grid[y][x] = '0'; // Replace with '0'
            }
            x++;
        }
        y++;
    }
    // printf("DEBUG: Player count = %d\n", player_count);
    return (player_count == 1);
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

int flood_fill_simple(char **map, char **visited, int x, int y, 
                      int width, int height, int depth)
{
    // 防止栈溢出
    if (depth > 10000)
        return (1);
    // 越界检查
    if (y < 0 || y >= height || x < 0)
        return (0);
    // 检查行长度
    int row_len = ft_strlen(map[y]);
    if (x >= row_len)
        return (0);
    // 空格是漏洞
    if (map[y][x] == ' ')
        return (0);
    // 墙，停止
    if (map[y][x] == '1')
        return (1);
    // 已访问
    if (visited[y][x])
        return (1);
    // 标记
    visited[y][x] = 1;
    // 四个方向
    if (!flood_fill_simple(map, visited, x, y - 1, width, height, depth + 1))
        return (0);
    if (!flood_fill_simple(map, visited, x, y + 1, width, height, depth + 1))
        return (0);
    if (!flood_fill_simple(map, visited, x - 1, y, width, height, depth + 1))
        return (0);
    if (!flood_fill_simple(map, visited, x + 1, y, width, height, depth + 1))
        return (0);
    return (1);
}
