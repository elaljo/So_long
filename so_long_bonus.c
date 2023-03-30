/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:40:08 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/29 21:40:09 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
	return (0);
}

void	open_window_bonus(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->len_rows * 50, data->len_columns * 50, "KOBE FOREVER");
	image_set(data);
	put_floor_in_window(data);
	put_images_into_window(data);
	mlx_key_hook(data->win_ptr, keygenerator, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275,
		3, 0x00000000, "Player moves:");
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		fd;

	data = malloc(sizeof(t_data));
	fd = open(argv[1], O_RDONLY);
	data->str = read_the_map(fd);
	if (data->str)
		size_of_r_c(data);
	if (argc == 2)
	{
		if (check_all_funcs(argv, data->str, fd) == 1)
			open_window_bonus(data);
		else
			ft_putstr_fd("Eroor\n ~Something wrong with the map, Fix it🤬", 1);
	}
	else
		ft_putstr_fd("Bad parameters input, Try again!", 1);
	return (0);
}