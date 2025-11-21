NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SOURCE =	get_next_line.c \
			get_next_line_utils.c

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
