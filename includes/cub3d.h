#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

// If you have libft, uncomment this:
// # include "../libft/libft.h"

// Screen dimensions
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

// Key codes (Linux)
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// Map structure
typedef struct s_map
{
    char    **grid;         // 地图二维数组
    int     width;          // 地图宽度
    int     height;         // 地图高度
    int     player_x;       // 玩家起始X
    int     player_y;       // 玩家起始Y
    char    player_dir;     // 玩家朝向 (N/S/E/W)
} t_map;

// Texture paths structure
typedef struct s_textures
{
    char    *north;         // 北墙纹理路径
    char    *south;         // 南墙纹理路径
    char    *west;          // 西墙纹理路径
    char    *east;          // 东墙纹理路径
} t_textures;

// Colors structure
typedef struct s_colors
{
    int     floor_r;        // 地板RGB
    int     floor_g;
    int     floor_b;
    int     ceiling_r;      // 天花板RGB
    int     ceiling_g;
    int     ceiling_b;
} t_colors;

// Parsed data structure
typedef struct s_data
{
    t_map       map;
    t_textures  textures;
    t_colors    colors;
    int         tex_count;      // 已解析的纹理数量
    int         color_count;    // 已解析的颜色数量
} t_data;

// Player structure for raycasting
typedef struct s_player
{
    double  posX;           // Player X position
    double  posY;           // Player Y position
    double  dirX;           // Direction vector X
    double  dirY;           // Direction vector Y
    double  planeX;         // Camera plane X (perpendicular to direction)
    double  planeY;         // Camera plane Y
    double  moveSpeed;      // Movement speed
    double  rotSpeed;       // Rotation speed
} t_player;

// Ray structure for raycasting calculations
typedef struct s_ray
{
    double  rayDirX;        // Ray direction X
    double  rayDirY;        // Ray direction Y
    int     mapX;           // Current map square X
    int     mapY;           // Current map square Y
    double  sideDistX;      // Distance to next X grid line
    double  sideDistY;      // Distance to next Y grid line
    double  deltaDistX;     // Distance ray travels between X grid lines
    double  deltaDistY;     // Distance ray travels between Y grid lines
    double  perpWallDist;   // Perpendicular distance to wall
    int     stepX;          // Step direction X (-1 or 1)
    int     stepY;          // Step direction Y (-1 or 1)
    int     side;           // Wall hit side (0=X-side, 1=Y-side)
    int     lineHeight;     // Height of wall on screen
    int     drawStart;      // Starting Y pixel for wall
    int     drawEnd;        // Ending Y pixel for wall
} t_ray;

// Image structure for MLX (screen buffer)
typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

// Loaded texture images structure
typedef struct s_tex_img
{
    void    *north;         // North wall MLX image
    void    *south;         // South wall MLX image
    void    *east;          // East wall MLX image
    void    *west;          // West wall MLX image
    char    *north_addr;    // North texture data address
    char    *south_addr;    // South texture data address
    char    *east_addr;     // East texture data address
    char    *west_addr;     // West texture data address
    int     width;          // Texture width
    int     height;         // Texture height
    int     bpp;            // Bits per pixel
    int     line_len;       // Line length
    int     endian;         // Endian
} t_tex_img;

// Main game structure
typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_data      data;
    t_player    player;
    t_img       img;
    t_tex_img   tex;
} t_game;

// ============= FUNCTION DECLARATIONS =============

// Validation functions (parsing/)
int         validate_data(t_data *data);
int         find_player_position(t_data *data);
int         validate_map_characters(t_data *data);
int         check_map_walls(t_data *data);
int         flood_fill(char **map, char **visited, int x, int y, 
                      int width, int height);

// Parsing functions (parsing/)
int         parse_file(char *filename, t_data *data);
int         parse_line(char *line, t_data *data);
int         parse_color(char *color_str, t_colors *colors, 
                       char type, t_data *data);
int         parse_texture(char *path, char **texture_ptr, t_data *data);
int         parse_map_line(char *line, t_data *data);

// Utils functions (utils/)
int         is_empty_line(char *line);
int         check_file_extension(char *filename, char *ext);
void        free_split(char **split);
char        **create_visited_array(int height, int width);
void        free_visited_array(char **visited, int height);

// Error functions (utils/)
int         error_msg(char *msg);
int         error_msg_prefix(char *prefix, char *msg);
void        exit_error(char *msg);

// Init and free functions (init/)
void        init_data(t_data *data);
void        free_data(t_data *data);
int         init_game(t_game *game, char *filename);
int         init_mlx(t_game *game);
void        init_player(t_game *game);
int         init_textures(t_game *game);
void        free_textures(t_game *game);

// Raycasting functions (raycasting/)
void        cast_rays(t_game *game);
void        calculate_ray_direction(t_player *player, int x, 
                                   double *rayDirX, double *rayDirY);
void        init_dda(t_ray *ray, double posX, double posY);
//void        perform_dda(t_ray *ray, char **map);
void        perform_dda(t_ray *ray, char **map, int height);
void        calculate_wall_distance(t_ray *ray, double posX, double posY);
void        calculate_wall_height(t_ray *ray);

// Texture functions (rendering/)
int         calculate_texture_x(t_ray *ray, double posX, double posY, 
                               int texWidth);
char        *select_wall_texture(t_ray *ray, t_game *game);

// Drawing functions (rendering/)
void        draw_textured_wall(t_game *game, t_ray *ray, int x);
void        render_frame(t_game *game);
void        draw_floor_ceiling(t_game *game);

// Movement functions (controls/)
void        move_forward(t_game *game);
void        move_backward(t_game *game);
void        move_left(t_game *game);
void        move_right(t_game *game);

// Rotation functions (controls/)
void        rotate_left(t_game *game);
void        rotate_right(t_game *game);

// Mouse functions (controls/)
int         mouse_rotate(int x, int y, t_game *game);
void        mouse_hide(t_game *game);
void        mouse_show(t_game *game);

// Hook management (controls/)
int         handle_keypress(int keycode, t_game *game);
void        setup_hooks(t_game *game);

// Graphics utilities (utils/)
void        put_pixel(t_game *game, int x, int y, int color);
int         get_texture_color(char *tex_addr, int x, int y, t_game *game);

// Cleanup and game loop (utils/)
int         close_game(t_game *game);
int         game_loop(t_game *game);


#endif