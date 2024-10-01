#ifndef PARSING_H
# define PARSING_H

#include "libft/libft.h"
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_texture
{
	int count_so;
	int count_no;
	int count_we;
	int count_ea;
	int count_c;
	int count_f;
	int direction;
}				t_texture;

typedef struct s_data
{
	int				fd;
	t_texture		*texture;
	char			**map;
	char			**map_cpy;
	unsigned int	columns;
	unsigned int	line;
	void			*mlx;
	void			*window;
}					t_data;

# endif