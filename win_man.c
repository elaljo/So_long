/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:27:50 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/09 03:27:51 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	data->count++;
	ft_putstr_fd("player moves: ", 1);
	ft_putnbr(data->count);
	ft_putchar('\n');
}

int	close_window(t_data *data)
{
	free_with_open_true(data);
	return (0);
}

void	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_without_open_false(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->len_rows * 50, data->len_columns * 50, "KOBE FOREVER");
	if (!data->win_ptr)
		free_without_open_false(data);
	image_set(data);
	put_floor_in_window(data);
	put_images_into_window(data);
	mlx_key_hook(data->win_ptr, keygenerator, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
