/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:58:25 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/24 00:58:26 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_helper(t_data *data)
{
	data->str[data->key_i][data->key_j] = '0';
	data->str[data->key_i][data->key_j + 1] = 'P';
}

void	move_left_helper(t_data *data)
{
	data->str[data->key_i][data->key_j] = '0';
	data->str[data->key_i][data->key_j - 1] = 'P';
}

void	move_forward_helper(t_data *data)
{
	data->str[data->key_i][data->key_j] = '0';
	data->str[data->key_i - 1][data->key_j] = 'P';
}

void	move_backward_helper(t_data *data)
{
	data->str[data->key_i][data->key_j] = '0';
	data->str[data->key_i + 1][data->key_j] = 'P';
}

void	print_player_moves(t_data *data)
{
	data->count++;
	ft_putstr_fd("player moves: ", 1);
	ft_putnbr_fd(data->count);
	ft_putchar_fd('\n');
}
