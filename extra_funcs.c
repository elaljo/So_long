/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:46:24 by moelalj           #+#    #+#             */
/*   Updated: 2023/04/11 02:46:25 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call_valid_path_funcs(t_data *data)
{
	check_path_c(data, data->x, data->y);
	valid_to_c(data);
	check_path_door(data, data->x, data->y);
	valid_to_door(data);
}

void	print_free_and_exit(t_data *data)
{
	ft_putstr_fd("Eroor\n ~Something wrong with the map, Fix it", 2);
	free_without_open_false(data);
}	

void	print_and_exit_param(void)
{
	ft_putstr_fd("Bad parameters input, Try again!", 2);
	exit (1);
}

void	print_and_exit(char *freestr)
{
	if (freestr)
		free(freestr);
	ft_putstr_fd("Eroor\n ~Something wrong with the map, Fix it", 2);
	exit (1);
}	

void	you_won(t_data *data)
{
	ft_putstr_fd("\033[1;33mREST IN PEACE\033[0m", 1);
	ft_putstr_fd("\033[1;35m KOBE BRYANT\033[0m", 1);
	free_with_open_true(data);
}
