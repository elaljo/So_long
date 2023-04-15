/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:32:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/12 21:32:47 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	open_fd_check(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("You have no file to read from", 1);
		exit (1);
	}
}

void	read_the_map(int fd, t_data *data)
{
	char	*fullmap;
	char	*line;
	int		i;

	fullmap = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		print_and_exit(NULL);
	if (line[0] == '\n')
		print_and_exit(line);
	while (line != NULL)
	{
		fullmap = ft_strjoin(fullmap, line);
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	while (fullmap[i])
		i++;
	if (fullmap[i - 1] == '\n')
		print_and_exit(fullmap);
	data->str = ft_split(fullmap, '\n');
	data->e_c_map = ft_split(fullmap, '\n');
	data->e_d_map = ft_split(fullmap, '\n');
	free(fullmap);
}
