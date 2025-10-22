/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <rxue@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:21:59 by r                 #+#    #+#             */
/*   Updated: 2025/10/22 13:22:01 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char		**grid;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	char		player_dir;
}	t_map;

// Texture paths structure
typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}	t_textures;

// Colors structure
typedef struct s_colors
{
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
}	t_colors;

// Parsed data structure
typedef struct s_data
{
	t_map		map;
	t_textures	textures;
	t_colors	colors;
	int			tex_count;
	int			color_count;
	int			map_started;
}	t_data;

// Player structure for raycasting
typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}	t_player;

// Ray structure for raycasting calculations
typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

// Image structure for MLX (screen buffer)
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

// Loaded texture images structure
typedef struct s_tex_img
{
	void		*north;
	void		*south;
	void		*east;
	void		*west;
	char		*north_addr;
	char		*south_addr;
	char		*east_addr;
	char		*west_addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}	t_tex_img;

// Main game structure
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_player	player;
	t_img		img;
	t_tex_img	tex;
}	t_game;

// ============= FUNCTION DECLARATIONS =============

// Parsing functions (parsing/)
int			parse_file(char *filename, t_data *data);
int			parse_line(char *line, t_data *data);
int			parse_color(char *color_str, t_colors *colors, \
	char type, t_data *data);
int			parse_texture(char *path, char **texture_ptr, t_data *data);
int			parse_map_line(char *line, t_data *data);
int			validate_map_connected(t_data *data);

// Validation functions (parsing/)
int			validate_map_characters(t_data *data);
int			validate_data(t_data *data);
int			find_player_position(t_data *data);
int			check_border_walls(t_data *data);
int			check_spaces_validity(t_data *data);
int			flood_fill(char **map, char **visited, int x, int y);
int			check_map_walls(t_data *data);
int			check_adjacent_horizontal(char *row, int x, int row_len);

// Utils functions (utils/)
int			is_empty_line(char *line);
int			check_file_extension(char *filename, char *ext);
void		free_split(char **split);
char		**create_visited_array(int height, int width);
void		free_visited_array(char **visited, int height);

// Error functions (utils/)
int			error_msg(char *msg);
int			error_msg_prefix(char *prefix, char *msg);
void		exit_error(char *msg);

// Init and free functions (init/)
void		init_data(t_data *data);
void		free_data(t_data *data);
int			init_game(t_game *game, char *filename);
int			init_mlx(t_game *game);
void		init_player(t_game *game);
int			init_textures(t_game *game);
void		free_textures(t_game *game);

// Raycasting functions (raycasting/)
void		cast_rays(t_game *game);
void		calculate_ray_direction(t_player *player, int x, \
	double *raydir_x, double *raydir_y);
void		init_dda(t_ray *ray, double pos_x, double pos_y);
void		perform_dda(t_ray *ray, char **map, int height);
void		calculate_wall_distance(t_ray *ray, double pos_x, double pos_y);
void		calculate_wall_height(t_ray *ray);

// Texture functions (rendering/)
int			calculate_texture_x(t_ray *ray, double pos_x, double pos_y, \
	int texWidth);
char		*select_wall_texture(t_ray *ray, t_game *game);

// Drawing functions (rendering/)
void		draw_textured_wall(t_game *game, t_ray *ray, int x);
void		render_frame(t_game *game);
void		draw_floor_ceiling(t_game *game);

// Movement functions (controls/)
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

// Rotation functions (controls/)
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);

// Mouse functions (controls/)
int			mouse_rotate(int x, int y, t_game *game);
void		mouse_hide(t_game *game);
void		mouse_show(t_game *game);

// Hook management (controls/)
int			handle_keypress(int keycode, t_game *game);
void		setup_hooks(t_game *game);

// Graphics utilities (utils/)
void		put_pixel(t_game *game, int x, int y, int color);
int			get_texture_color(char *tex_addr, int x, int y, t_game *game);

// Cleanup and game loop (utils/)
int			close_game(t_game *game);
int			game_loop(t_game *game);

#endif
