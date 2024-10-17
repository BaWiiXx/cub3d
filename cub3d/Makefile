# NAME = cub3d
# CC = clang
# CFLAGS = -Wall -Wextra -Werror -Iincludes

# ifdef DEBUG
# CFLAGS += -g
# endif

# ifdef CHECK
# CFLAGS += -fsanitize=address
# endif

# HEADERS = parsing.h

# SRC_DIR	= src
# OBJ_DIR	= obj
# DIRDUP	= mkdir -p $(@D)


# SRC	=main.c \
# 	 ft_split.c \
# 	 have_map.c \
#      parsing_arg_and_fd.c \
# 	 parsing_color.c \
# 	 parsing_map.c \
# 	 get_next_line/get_next_line.c \
# 	 get_next_line/get_next_line_utils.c \
#  	 free_and_error.c \
# 	 parsing_map_utils.c \
# 	 parsing_pos_player.c \
#  	 parsing_texture.c \
# 	 parsing_utils.c \
# 	 parsing_utils2.c \
# 	 parsing_utils3.c \
		
# SRC		:= $(SRC:%=$(SRC_DIR)/%)
# OBJ 	:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	 $(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)


# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
# 	$(DIRDUP)
# 	$(CC) $(CFLAGS) $< -c -o $@

# clean:
# 	rm -f $(OBJ)
	
# fclean: clean
# 	rm -f $(NAME)
# 	rm -f $(LIBFT)

# re: fclean all

# .PHONY: all fclean clean re

# CC=cc
# NAME = cub3d
# LIBMLX	= MLX42
# SRCS = src/main.c \
# 	   src/ft_split.c \
# 	   src/have_map.c \
#  	   src/parsing_arg_and_fd.c \
# 	   src/parsing_color.c \
# 	   src/parsing_map.c \
#  	   src/parsing_utils.c \
# 	   src/get_next_line/get_next_line.c \
# 	   src/get_next_line/get_next_line_utils.c \
#  	   src/free_and_error.c \
# 	   src/parsing_map_utils.c \
# 	   src/parsing_pos_player.c \
#  	   src/parsing_texture.c \
# 	   src/parsing_utils.c \
# 	   src/parsing_utils2.c \
# 	   src/parsing_utils3.c \

# HEADERS = -I includes -I $(LIBMLX)/include
# OBJS = $(SRCS.c=.o)
# CFLAGS = -Wall -Wextra -Werror -g
# LFLAGS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 

# all: $(NAME)

# %.o : %.c
# 	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# $(NAME): $(OBJS) $(LIBFT)
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make --no-print-directory -C $(LIBMLX)/build -j4
# 	$(CC) $(OBJS) $(LFLAGS) $(HEADERS) -o $(NAME)


# fclean: clean
# 	rm -f $(NAME)
# 	rm -rf $(LIBMLX)/build

# clean:
# 	rm -f $(OBJS)

# re: fclean all

# .PHONY: all fclean clean re

CC = cc
NAME = cub3d
LIBMLX = MLX42

SRCS = src/main.c \
	   src/ft_split.c \
	   src/have_map.c \
 	   src/parsing_arg_and_fd.c \
	   src/parsing_color.c \
	   src/parsing_map.c \
 	   src/parsing_utils.c \
	   src/get_next_line/get_next_line.c \
	   src/get_next_line/get_next_line_utils.c \
 	   src/free_and_error.c \
	   src/parsing_map_utils.c \
	   src/parsing_pos_player.c \
 	   src/parsing_texture.c \
	   src/parsing_utils2.c \
	   src/parsing_utils3.c

HEADERS = -I includes -I $(LIBMLX)/include
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make --no-print-directory -C $(LIBMLX)/build -j4
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBMLX)/build

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re