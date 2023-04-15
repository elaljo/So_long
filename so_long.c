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
	t_data	data;
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		open_fd_check(&fd, argv[1]);
		read_the_map(fd, &data);
		if (data.str)
		{
			size_of_r_c_check_map_big(&data);
			find_cor_player(&data);
			if (check_all_funcs(argv, data) == 1)
			{
				call_valid_path_funcs(&data);
				open_window(&data);
			}
		}
		print_free_and_exit(&data);
	}
	else
		print_and_exit_param();
	return (0);
}
