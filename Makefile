NAME = so_long

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = check_errors.c\
				check_map.c\
				check_map2.c\
				check_valid_path.c\
				ft_split.c\
				get_next_line_utils.c\
				get_next_line.c\
				key_man_2.c\
				key_man.c\
				libft_nedeed.c\
				read_map.c\
				so_long.c\
				substr_helper.c\
				win_man.c

OBJ = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : $(OBJ)
	$(CC) $(MLX) $(CFLAGS) $(OBJ) -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re