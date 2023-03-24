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

char	**read_the_map(int fd)
{
	char	*fullmap;
	char	*line;
	char	**ptr;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	fullmap = NULL;
	while (line != NULL)
	{
		fullmap = ft_strjoin(fullmap, line);
		line = get_next_line(fd);
	}
	ptr = ft_split(fullmap, '\n');
	return (ptr);
}
