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
	int		i;
	char	*fullmap;
	char	*line;
	char	**ptr;

	fullmap = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line != NULL)
	{
		if (line[0] == '\n')
			return (NULL);
		fullmap = ft_strjoin(fullmap, line);
		line = get_next_line(fd);
	}
	i = 0;
	while (fullmap[i])
		i++;
	if (fullmap[i - 1] == '\n')
		return (NULL);
	ptr = ft_split(fullmap, '\n');
	return (ptr);
}
