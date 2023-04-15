/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:05:41 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/07 12:05:42 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(t_data *data, int h, int v)
{
	data->i = -1;
	while (data->str[++data->i])
	{
		data->j = -1;
		while (data->str[data->i][++data->j])
		{
			if ((data->str[data->i][data->j] == 'P')
				&& (data->collectibles_counter == 0)
				&& (data->str[data->i + v][data->j + h] == 'E'))
				you_won(data);
			else if ((data->str[data->i][data->j] == 'P')
				&& (data->str[data->i + v][data->j + h] != '1')
				&& (data->str[data->i + v][data->j + h] != 'E'))
			{
				data->str[data->i][data->j] = '0';
				data->str[data->i + v][data->j + h] = 'P';
				put_images_into_window(data);
				print_moves_bonus(data);
				return ;
			}
		}
	}
}

int	keygenerator(int key_code, t_data *data)
{
	if (key_code == ESC)
		free_with_open_true(data);
	else if (key_code == MOVE_RIGHT)
		move(data, 1, 0);
	else if (key_code == MOVE_LEFT)
		move(data, -1, 0);
	else if (key_code == MOVE_FORWARD)
		move(data, 0, -1);
	else if (key_code == MOVE_BACKWARD)
		move(data, 0, 1);
	return (1);
}
