/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:22:55 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/13 17:25:19 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		fd;

	data = malloc(sizeof(t_data));
	fd = open("map.ber", O_RDONLY);
	data->str = read_the_map(fd);
	if (data->str)
		size_of_r_c(data);
	if (argc == 2)
	{
		if (check_all_funcs(argv, data->str , fd) == 1)
					open_window(data);
		else
			ft_putstr_fd("Eroor\n ~Something wrong with the map, Fix it🤬", 1);
	}
	else
		ft_putstr_fd("Bad parameters input, Try again!", 1);
	return (0);
}
