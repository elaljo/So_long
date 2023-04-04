/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:41:09 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/29 21:41:13 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define MOVE_FORWARD 13
# define MOVE_BACKWARD 1
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define ESC 53

struct s_maxmembers
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;
};

typedef struct s_data
{
	int		i;
	int		j;
	int		count;
	int		collectibles_counter;

	void	*ptr_1_img;
	void	*ptr_0_img;
	void	*ptr_e_img;
	void	*ptr_c_img;
	void	*ptr_p_img;

	char	**str;

	int		len_columns;
	int		len_rows;

	int		width;
	int		height;

	void	*mlx_ptr;
	void	*win_ptr;
}							t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
//get_next_line
char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*copy_to_xyata(char *str);
char	*cut(char *str);
char	*ft_read(char *all, int fd);
char	*get_next_line(int fd);
														//libft --> spl
char	**ft_split(char const *s, char c);		
int		count_chars(char const *s, char delimiter, int lens);
int		count_words(char const *s, char delimiter);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
void	ft_bzero(void *s, size_t n);
														//libft --> nedeed
char	*ft_itoa(int n);
int		if_stuff(int n, char *str);
int		counter(int c);
void	ft_putstr_fd(char *s, int fd);

char	**read_the_map(int fd);
														//check_funcs
int		check_characters(char **str);
int		check_max_characters(char **str);
int		check_rows_walls(char **str);
int		check_columns_walls(char **str);
int		check_if_rectangular(char **str);
int		check_ending_extension(char **argv);

void	open_window_bonus(t_data *data);
int		close_window(t_data *data);

void	size_of_r_c(t_data *data);
void	put_floor_in_window(t_data *data);
void	put_images_into_window(t_data *data);
void	put_collectibles_into_window(t_data *data);
void	image_set(t_data *data);

int		keygenerator(int key_code, t_data *data);
void	move(t_data *data, int H, int V);

void	print_player_moves(t_data *data);

int		check_all_funcs(char *argv[], t_data data);

#endif