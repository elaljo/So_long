/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_man_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:06:19 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/29 22:06:24 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275,
		3, 0x00000000, "Player moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 410,
		3, 0x00004200, ft_itoa(++data->count));
}
