NAME = cub3d
CC = clang
CFLAGS = -Wall -Wextra -Werror -Iincludes

ifdef DEBUG
CFLAGS += -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
endif

HEADERS = parsing.h

SRC_DIR	= src
OBJ_DIR	= obj
DIRDUP	= mkdir -p $(@D)

SRC	= main.c ft_split.c have_map.c parsing_arg_and_fd.c parsing_color.c \
		parsing_map.c parsing_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
		
SRC		:= $(SRC:%=$(SRC_DIR)/%)
OBJ 	:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ 


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(DIRDUP)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean clean re
