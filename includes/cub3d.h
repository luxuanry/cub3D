// includes/cub3d.h
#include <fcntl.h>
#include <stddef.h>

typedef struct s_map
{
    char    **grid;          // 地图二维数组
    int     width;           // 地图宽度
    int     height;          // 地图高度
    int     player_x;        // 玩家起始X
    int     player_y;        // 玩家起始Y
    char    player_dir;      // 玩家朝向 (N/S/E/W)
}   t_map;

typedef struct s_textures
{
    char    *north;          // 北墙纹理路径
    char    *south;          // 南墙纹理路径
    char    *west;           // 西墙纹理路径
    char    *east;           // 东墙纹理路径
}   t_textures;

typedef struct s_colors
{
    int     floor_r;         // 地板RGB
    int     floor_g;
    int     floor_b;
    int     ceiling_r;       // 天花板RGB
    int     ceiling_g;
    int     ceiling_b;
}   t_colors;

typedef struct s_data
{
    t_map       map;
    t_textures  textures;
    t_colors    colors;
    int         tex_count;   // 已解析的纹理数量
    int         color_count; // 已解析的颜色数量
}   t_data;