#ifndef PARSING_H
# define PARSING_H


#include <stdint.h>
#include <stdio.h>


typedef struct s_game
{
	int				fd;
	char			**map;
	char			**map_cpy;
	unsigned int	columns;
	unsigned int	line;
	void			*mlx;
	void			*window;
}					t_game;

# endif