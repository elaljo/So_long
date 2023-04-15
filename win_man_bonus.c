/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:52:37 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/11 02:52:38 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves_bonus(t_data *data)
{
	char	*str;

	str = ft_itoa(++data->count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75,
		3, 0x00000000, "Player moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 205,
		3, 0x00004200, str);
	free(str);
}

int	close_window(t_data *data)
{
	free_with_open_true(data);
	return (0);
}

void	open_window_bonus(t_data *data)
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75,
		3, 0x00000000, "Player moves:");
	mlx_loop(data->mlx_ptr);
}
