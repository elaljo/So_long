/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:04:09 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/15 11:04:10 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ending_extension(char *argv[])
{
	int		len_file;
	char	*file_name;

	file_name = argv[1];
	len_file = ft_strlen(argv[1]);
	if ((file_name[len_file - 1] != 'r') || (file_name[len_file - 2] != 'e')
		|| (file_name[len_file - 3] != 'b') || (file_name[len_file - 4] != '.'))
		return (0);
	return (1);
}

int	check_all_funcs(char *argv[], t_data data)
{
	if (check_ending_extension(argv) != 1)
		return (0);
	if (check_characters(data.str) != 1)
		return (0);
	if (check_max_characters(data.str) != 1)
		return (0);
	if (check_rows_walls(data.str) != 1)
		return (0);
	if (check_columns_walls(data.str) != 1)
		return (0);
	if (check_if_rectangular(data.str) != 1)
		return (0);
	return (1);
}

void	check_images(t_data *data)
{
	if (!data->ptr_0_img || !data->ptr_1_img || !data->ptr_c_img
		|| !data->ptr_e_img || !data->ptr_p_img)
	{
		ft_putstr_fd("Error - i cannot find the image", 2);
		destroy_images(data);
		free_without_open_false(data);
	}
}

void	destroy_images(t_data *data)
{
	if (data->ptr_0_img)
		mlx_destroy_image(data->mlx_ptr, data->ptr_0_img);
	if (data->ptr_1_img)
		mlx_destroy_image(data->mlx_ptr, data->ptr_1_img);
	if (data->ptr_c_img)
		mlx_destroy_image(data->mlx_ptr, data->ptr_c_img);
	if (data->ptr_e_img)
		mlx_destroy_image(data->mlx_ptr, data->ptr_e_img);
	if (data->ptr_p_img)
		mlx_destroy_image(data->mlx_ptr, data->ptr_p_img);
}
