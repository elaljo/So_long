/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:16:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/01 12:16:48 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		x;
	int		y;
	void	*ptr_1_img;
	void	*ptr_0_img;
	void	*ptr_e_img;
	void	*ptr_c_img;
	void	*ptr_p_img;
	char	**str;
	char	**e_c_map;
	char	**e_d_map;
	int		len_columns;
	int		len_rows;
	int		tex_width;
	int		tex_height;
	void	*mlx_ptr;
	void	*win_ptr;
}							t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*copy_to_xyata(char *str);
char	*cut(char *str);
char	*ft_read(char *all, int fd);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);		
int		count_chars(char const *s, char delimiter, int lens);
int		count_words(char const *s, char delimiter);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	print_free_and_exit(t_data *data);
void	print_and_exit(char *freestr);
void	read_the_map(int fd, t_data *data);
void	open_fd_check(int *fd, char *file);
int		check_characters(char **str);
int		check_max_characters(char **str);
int		check_rows_walls(char **str);
int		check_columns_walls(char **str);
int		check_if_rectangular(char **str);
int		check_ending_extension(char *argv[]);
void	check_images(t_data *data);
int		close_window(t_data *data);
void	open_window(t_data *data);
void	image_set(t_data *data);
void	size_of_r_c_check_map_big(t_data *data);
void	put_floor_in_window(t_data *data);
void	put_images_into_window(t_data *data);
void	put_collectibles_into_window(t_data *data);
int		keygenerator(int key_code, t_data *data);
void	move(t_data *data, int v, int h);
void	print_moves(t_data *data);
int		check_all_funcs(char *argv[], t_data data);
void	find_cor_player(t_data *data);
void	check_path_c(t_data *data, int x, int y);
void	check_path_door(t_data *data, int x, int y);
void	valid_to_c(t_data *data);
void	valid_to_door(t_data *data);
void	call_valid_path_funcs(t_data *data);
void	you_won(t_data *data);
void	ft_free(char	**arr);
void	free_without_open_true(t_data *data);
void	free_without_open_false(t_data *data);
void	free_with_open_false(t_data *data);
void	free_with_open_true(t_data *data);
void	print_and_exit_param(void);
void	destroy_images(t_data *data);
void	check_last_nl(char *fullmap);

#endif