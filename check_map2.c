/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:22:29 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/17 16:22:30 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ending_extension(char **argv)
{
	int		len_file;
	int		i;
	char	*file_name;

	i = 0;
	file_name = argv[1];
	len_file = ft_strlen(argv[1]);
	if ((file_name[len_file - 1] != 'r') || (file_name[len_file - 2] != 'e')
		|| (file_name[len_file - 3] != 'b') || (file_name[len_file - 4] != '.'))
		return (0);
	return (1);
}

int	check_empty_map(int fd)
{
	if (read_the_map(fd) == NULL)
		return (0);
	return (1);
}

int	check_nl_inside(int fd)
{
	char	*fullmap;
	char	*line;
	int		i;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	fullmap = NULL;
	while (line != NULL)
	{
		fullmap = ft_strjoin(fullmap, line);
		line = get_next_line(fd);
	}
	i = 0;
	while (fullmap[i])
	{
		if (fullmap[i] == '\n')
			i++;
		if (fullmap[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_nl_1st_last_line(int fd)
{
	char	*full_map;
	char	*line;
	int		i;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (line[0] == '\n')
		return (0);
	full_map = NULL;
	while (line != NULL)
	{
		full_map = ft_strjoin(full_map, line);
		line = get_next_line(fd);
	}
	i = 0;
	while (full_map[i])
		i++;
	if (full_map[i - 1] == '\n')
		return (0);
	return (1);
}
