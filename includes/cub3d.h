#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// 如果你有 libft
// # include "libft.h"

// 如果没有 libft，需要这些函数声明
int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_strncmp(char *s1, char *s2, int n);
char    *ft_strdup(char *s);
char    *ft_strtrim(char *s, char *set);
char    **ft_split(char *s, char c);
int     ft_atoi(char *str);
void    ft_putstr_fd(char *s, int fd);
int     get_next_line(int fd, char **line);


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

//validate function
int     validate_data(t_data *data);
int     find_player_position(t_data *data);
int     validate_map_characters(t_data *data);
int     check_map_walls(t_data *data);
int     flood_fill(char **map, char **visited, int x, int y, int width, int height);

//utils
int     is_empty_line(char *line);
int     check_file_extension(char *filename, char *ext);
void    free_split(char **split);

/*utils array*/
char **create_visited_array(int height, int width);
void free_visited_array(char **visited, int height);

// error
int     error_msg(char *msg);
int     error_msg_prefix(char *prefix, char *msg);
void    exit_error(char *msg);

// init and free
void    init_data(t_data *data);
void    free_data(t_data *data);


#endif