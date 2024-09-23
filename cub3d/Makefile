NAME = cub3d
CC = clang
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

ifdef DEBUG
CFLAGS += -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
endif

LIBFT = libft/libft.a
HEADERS = cub3d.h

SRC_DIR	= src
OBJ_DIR	= obj
DIRDUP	= mkdir -p $(@D)

SRC	= main.c
		
SRC		:= $(SRC:%=$(SRC_DIR)/%)
OBJ 	:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@ 

$(LIBFT):
	@make -j8 -C libft/ all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(DIRDUP)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)
	@make -C libft/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean clean re
