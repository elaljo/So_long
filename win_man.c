/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:18:30 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/21 16:18:38 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_of_r_c(t_data *data)
{
	data->len_columns = 0;
	data->len_rows = 0;
	data->len_rows = ft_strlen(data->str[1]);
	while (data->str[data->len_columns])
		data->len_columns++;
}

void	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->len_rows * 50, data->len_columns * 50, "R.I.P || 24");
	image_set(data);
	put_floor_in_window(data);
	put_images_into_window(data);
	mlx_key_hook(data->win_ptr, keygenerator, data);
	mlx_loop(data->mlx_ptr);
}

void	put_floor_in_window(t_data *data)
{
	data->j = 0;
	while(data->str[data->i])
	{
		data->j = 0;
		while (data->str[data->i][data->j])
		{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_0_img , data->j * 50, data->i * 50);
				data->j++;
		}
			data->i++;
	}
}

void	image_set(t_data *data)
{
	data->width = 50;
	data->height = 50;
	data->ptr_1_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall.xpm", &data->width, &data->height);
	data->ptr_0_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &data->width, &data->height);
	data->ptr_e_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm", &data->width, &data->height);
	data->ptr_c_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/ball.xpm", &data->width, &data->height);
	data->ptr_p_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/PLAYERKOBE.xpm", &data->width, &data->height);
}

void	put_images_into_window(t_data *data)
{
	data->collectibles_counter = 0;
	data->i = 0;
	while (data->str[data->i])
	{
		data->j = 0;
		while (data->str[data->i][data->j])
		{
			if (data->str[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_1_img , data->j * 50 , data->i * 50);
			else if (data->str[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_e_img , data->j * 50, data->i * 50);
			else if (data->str[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_p_img , data->j * 50, data->i * 50);
			else if (data->str[data->i][data->j] == 'C')
			{
				data->collectibles_counter++;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_c_img , data->j * 50, data->i * 50);
			}
			else if (data->str[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr_0_img , data->j * 50, data->i * 50);
			data->j++;
		}
		data->i++;
	}
}
