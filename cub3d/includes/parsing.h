#ifndef PARSING_H
# define PARSING_H

#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../get_next_line/get_next_line.h" 

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
	int				columns;
	int				line;
}					t_data;

int 	is_whitespaces(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
void 	free_tab(char **tab);
char	**ft_split(char const *s, char c);
char	**get_map(int fd);
void	check_cub_argv(char *argv);
int 	open_fd(t_data *data,  char **argv);
int		check_map(t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

# endif