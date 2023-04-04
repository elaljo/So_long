NAME = so_long

SL_BONUS = so_long_bonus

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CFILES = check_errors.c\
				check_map.c\
				check_valid_path.c\
				ft_split.c\
				get_next_line_utils.c\
				get_next_line.c\
				print_moves.c\
				key_man.c\
				libft_nedeed.c\
				read_map.c\
				so_long.c\
				substr_helper.c\
				win_man.c

CFILES_BONUS = check_errors.c\
				check_map.c\
				check_valid_path.c\
				ft_split.c\
				get_next_line_utils.c\
				get_next_line.c\
				print_moves_bonus.c\
				key_man.c\
				libft_nedeed_bonus.c\
				read_map.c\
				so_long_bonus.c\
				substr_helper.c\
				win_man.c

OBJ = ${CFILES:.c=.o}

OBJ_BONUS = ${CFILES_BONUS:.c=.o}

all : $(NAME)

bonus : $(SL_BONUS)

$(SL_BONUS) : $(OBJ_BONUS)
	$(CC) $(MLX) $(CFLAGS) $^ -o $@

$(NAME) : $(OBJ)
	$(CC) $(MLX) $(CFLAGS) $^ -o $@
	
clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(SL_BONUS)

re : fclean all

.PHONY : all clean fclean re