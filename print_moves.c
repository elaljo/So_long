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

void	print_player_moves(t_data *data)
{
	data->count++;
	ft_putstr_fd("player moves: ", 1);
	ft_putnbr(data->count);
	ft_putchar('\n');
}
