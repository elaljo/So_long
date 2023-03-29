/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:17 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/22 17:34:20 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
	data->key_i = 0;
	while (data->str[data->key_i])
	{
		data->key_j = 0;
		while (data->str[data->key_i][data->key_j++])
		{
			if ((data->str[data->key_i][data->key_j] == 'P')
				&& (data->collectibles_counter == 0)
				&& (data->str[data->key_i][data->key_j + 1] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[data->key_i][data->key_j] == 'P')
							&& (data->str[data->key_i][data->key_j + 1] != '1')
							&& (data->str[data->key_i][data->key_j + 1] != 'E'))
			{
				move_right_helper(data);
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		data->key_i++;
	}
}

void	move_left(t_data *data)
{
	data->key_i = 0;
	while (data->str[data->key_i])
	{
		data->key_j = 0;
		while (data->str[data->key_i][data->key_j++])
		{
			if ((data->str[data->key_i][data->key_j] == 'P')
					&& (data->collectibles_counter == 0)
					&& (data->str[data->key_i][data->key_j - 1] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[data->key_i][data->key_j] == 'P')
							&& (data->str[data->key_i][data->key_j - 1] != '1')
							&& (data->str[data->key_i][data->key_j - 1] != 'E'))
			{
				move_left_helper(data);
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		data->key_i++;
	}
}

void	move_forward(t_data *data)
{
	data->key_i = 0;
	while (data->str[data->key_i])
	{
		data->key_j = 0;
		while (data->str[data->key_i][data->key_j++])
		{
			if ((data->str[data->key_i][data->key_j] == 'P')
					&& (data->collectibles_counter == 0)
					&& (data->str[data->key_i - 1][data->key_j]) == 'E')
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[data->key_i][data->key_j] == 'P')
							&& (data->str[data->key_i - 1][data->key_j] != '1')
							&& (data->str[data->key_i - 1][data->key_j] != 'E'))
			{
				move_forward_helper(data);
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		data->key_i++;
	}
}

void	move_backward(t_data *data)
{
	data->key_i = 0;
	while (data->str[data->key_i])
	{
		data->key_j = 0;
		while (data->str[data->key_i][data->key_j++])
		{
			if ((data->str[data->key_i][data->key_j] == 'P')
					&& (data->collectibles_counter == 0)
					&& (data->str[data->key_i + 1][data->key_j] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[data->key_i][data->key_j] == 'P')
							&& (data->str[data->key_i + 1][data->key_j] != '1')
							&& (data->str[data->key_i + 1][data->key_j] != 'E'))
			{
				move_backward_helper(data);
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		data->key_i++;
	}
}

int	keygenerator(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit(0);
	else if (key_code == MOVE_RIGHT)
		move_right(data);
	else if (key_code == MOVE_LEFT)
		move_left(data);
	else if (key_code == MOVE_FORWARD)
		move_forward(data);
	else if (key_code == MOVE_BACKWARD)
		move_backward(data);
	return (1);
}
