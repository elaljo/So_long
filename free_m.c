/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:21:41 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/13 23:21:41 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_without_open_true(t_data *data)
{
	ft_free(data->str);
	ft_free(data->e_c_map);
	ft_free(data->e_d_map);
	exit(0);
}

void	free_without_open_false(t_data *data)
{
	ft_free(data->str);
	ft_free(data->e_c_map);
	ft_free(data->e_d_map);
	exit(1);
}

void	free_with_open_false(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->ptr_0_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_1_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_e_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_c_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_p_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free(data->str);
	ft_free(data->e_c_map);
	ft_free(data->e_d_map);
	exit(1);
}

void	free_with_open_true(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->ptr_0_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_1_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_e_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_c_img);
	mlx_destroy_image(data->mlx_ptr, data->ptr_p_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free(data->str);
	ft_free(data->e_c_map);
	ft_free(data->e_d_map);
	exit(0);
}

void	ft_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr[i]);
	free(arr);
}
