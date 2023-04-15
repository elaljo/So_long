/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:30 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/06 23:01:47 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_cor_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->str[x])
	{
		y = 0;
		while (data->str[x][y])
		{
			if (data->str[x][y] == 'P')
			{
				data->x = x;
				data->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	check_path_c(t_data *data, int x, int y)
{
	data->e_c_map[x][y] = '1';
	if (data->e_c_map[x - 1][y] != '1' && data->e_c_map[x - 1][y] != 'E')
		check_path_c(data, x - 1, y);
	if (data->e_c_map[x][y + 1] != '1' && data->e_c_map[x][y + 1] != 'E')
		check_path_c(data, x, y + 1);
	if (data->e_c_map[x + 1][y] != '1' && data->e_c_map[x + 1][y] != 'E')
		check_path_c(data, x + 1, y);
	if (data->e_c_map[x][y - 1] != '1' && data->e_c_map[x][y - 1] != 'E')
		check_path_c(data, x, y - 1);
}

void	valid_to_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->e_c_map[i])
	{
		j = 0;
		while (data->e_c_map[i][j])
		{
			if (data->e_c_map[i][j] == 'C')
			{
				ft_putstr_fd ("THERE IS NO PATH TO THE COINS", 1);
				free_without_open_false(data);
			}
			j++;
		}
		i++;
	}
}

void	check_path_door(t_data *data, int x, int y)
{
	data->e_d_map[x][y] = '1';
	if (data->e_d_map[x - 1][y] != '1')
		check_path_door(data, x - 1, y);
	if (data->e_d_map[x][y + 1] != '1')
		check_path_door(data, x, y + 1);
	if (data->e_d_map[x + 1][y] != '1')
		check_path_door(data, x + 1, y);
	if (data->e_d_map[x][y - 1] != '1')
		check_path_door(data, x, y - 1);
}

void	valid_to_door(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->e_d_map[i])
	{
		j = 0;
		while (data->e_d_map[i][j])
		{
			if (data->e_d_map[i][j] == 'E')
			{
				ft_putstr_fd ("THERE IS NO PATH TO THE DOOR", 1);
				free_without_open_false(data);
			}
			j++;
		}
		i++;
	}
}
