#include "../../includes/cub3d.h"

void init_data(t_data *data)
{
    data->map.grid = NULL;
    data->map.width = 0;
    data->map.height = 0;
    data->map.player_x = -1;
    data->map.player_y = -1;
    data->map.player_dir = '\0';
    
    data->textures.north = NULL;
    data->textures.south = NULL;
    data->textures.west = NULL;
    data->textures.east = NULL;
    
    data->colors.floor_r = -1;
    data->colors.floor_g = -1;
    data->colors.floor_b = -1;
    data->colors.ceiling_r = -1;
    data->colors.ceiling_g = -1;
    data->colors.ceiling_b = -1;
    
    data->tex_count = 0;
    data->color_count = 0;
}

void free_data(t_data *data)
{
    int i;
    if (data->textures.north)
        free(data->textures.north);
    if (data->textures.south)
        free(data->textures.south);
    if (data->textures.west)
        free(data->textures.west);
    if (data->textures.east)
        free(data->textures.east);
    
    // 释放地图
    if (data->map.grid)
    {
        i = 0;
        while (i < data->map.height)
        {
            free(data->map.grid[i]);
            i++;
        }
        free(data->map.grid);
    }
}
