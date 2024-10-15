/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:41:12 by bdany             #+#    #+#             */
/*   Updated: 2024/10/15 16:02:14 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef PARSING_H
// # define PARSING_H

// #include <stdint.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include "../get_next_line/get_next_line.h" 

// typedef struct s_texture
// {
// 	int count_so;
// 	int count_no;
// 	int count_we;
// 	int count_ea;
// 	int count_c;
// 	int count_f;
// 	int direction;
// }				t_texture;

// typedef struct s_data
// {
// 	int				fd;
// 	t_texture		*texture;
// 	char			**map;
// 	int				columns;
// 	int				line;
// }					t_data;

// int 	is_whitespaces(char *str);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
// void	*ft_memset(void *s, int c, size_t n);
// int		ft_atoi(const char *nptr);
// void 	free_tab(char **tab);
// char	**ft_split(char const *s, char c);
// char	**get_map(int fd);
// void	check_cub_argv(char *argv);
// int 	open_fd(t_data *data,  char **argv);
// int		check_map(t_data *data);
// char	*ft_strjoin(char const *s1, char const *s2);
// int		ft_strcmp(const char *s1, const char *s2);
// int	ft_strncmp(const char *s1, const char *s2, size_t n);

// # endif

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "../get_next_line/get_next_line.h" 
#include "../MLX42/include/MLX42/MLX42.h"

# define S_W 1080
# define S_H 720
# define T_W 64
# define T_H 64
# define SPEED 0.06
# define ROTATE_SPEED 0.05
# define WALL_DISTANCE 5

typedef struct s_ceilfloor
{
	int ceil_color;
	int floor_color;
}		t_ceilfloor;

typedef struct s_text
{
	mlx_image_t	*texture[4];
	mlx_texture_t	*path[4];
	int 		count_so;
	int 		count_no;
	int 		count_we;
	int 		count_ea;
	int 		count_c;
	int			count_f;
	int			direction;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;
}				t_text;

typedef struct s_player
{
	double	x;
	double	y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	old_dirx;
	double	old_planex;
}			t_player;

typedef struct s_map
{
	char		*f_color;
	char		*c_color;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			columns;
	int			line;
	int 		dir;
	char		**map;
}				t_map;

typedef struct s_ray
{
	double	ray_x;
	double	ray_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}			t_ray;

typedef struct s_game
{
	int			fd;
	int			x;
	int			y;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_text		texture;
	t_ceilfloor	ceilfloor;
}				t_game;

void		init_map(t_game *game);
void		init_player(t_game *game);
void		init_text(t_game *game);

void		parsing(t_map map, t_player player);

void		start_game(t_game *game);

void		move(t_game *game);
void		rotate2(t_game *game);
void		update(t_game *game);
uint32_t	get_color_rgba(int r, int g, int b, int a);
void 		set_color(t_game *data, char *line);

void		raycasting(t_game *game);
void		raycasting2(t_game *game);
void		raycasting3(t_game *game);
void		raycasting4(t_game *game);
void		raycasting5(t_game *game);

void		draw_ceiling_floor(t_game *game, int draw_start,
				int draw_end, uint32_t color);
void		draw_textures(t_game *game);

void		free_all(t_game *game);

//fonction for check map
int check_line(char *str, t_game *data);
int	is_char_valid(char c);
void	exit_error(char *str);

int 	is_whitespaces(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
void 	free_tab(char **tab);
char	**ft_split(char const *s, char c);
char	**get_map(int fd);
void	check_cub_argv(char *argv);
int 	open_fd(t_game *data,  char **argv);
int		check_map(t_game *data);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
#endif