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
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j++])
		{
			if ((data->str[i][j] == 'P') && (data->collectibles_counter == 0) && (data->str[i][j + 1] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[i][j] == 'P') && (data->str[i][j + 1] != '1') && (data->str[i][j + 1] != 'E'))
			{
				data->str[i][j] = '0';
				data->str[i][j + 1] = 'P';
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		i++;
	}
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j++])
		{
			if ((data->str[i][j] == 'P') && (data->collectibles_counter == 0) && (data->str[i][j - 1] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[i][j] == 'P') && (data->str[i][j - 1] != '1') && (data->str[i][j - 1] != 'E'))
			{
				data->str[i][j] = '0';
				data->str[i][j - 1] = 'P';
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		i++;
	}
}

void	move_forward(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j++])
		{
			if ((data->str[i][j] == 'P') && (data->collectibles_counter == 0) && (data->str[i - 1][j]) == 'E')
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[i][j] == 'P') && (data->str[i - 1][j] != '1') && (data->str[i - 1][j] != 'E'))
			{
				data->str[i][j] = '0';
				data->str[i - 1][j] = 'P';
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		i++;
	}
}

void	move_backward(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j++])
		{
			if ((data->str[i][j] == 'P') && (data->collectibles_counter== 0) && (data->str[i + 1][j] == 'E'))
			{
				print_player_moves(data);
				exit(0);
			}
			else if ((data->str[i][j] == 'P') && (data->str[i + 1][j] != '1') && (data->str[i + 1][j] != 'E'))
			{
				data->str[i][j] = '0';
				data->str[i + 1][j] = 'P';
				put_images_into_window(data);
				print_player_moves(data);
				return ;
			}
		}
		i++;
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
