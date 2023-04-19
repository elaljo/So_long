/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:42:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/03 15:08:12 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy_to_xyata(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc (ft_strlen (str) - i + 1);
	while (str[i] != '\0')
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	free(str);
	return (s);
}

char	*cut(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc (i + 1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read(char *all, int fd)
{
	int		n;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	n = 1;
	while (n > 0 && !(ft_strchr(all, '\n')))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			free(all);
			all = NULL;
			return (all);
		}
		buff[n] = '\0';
		all = ft_strjoin(all, buff);
	}
	free(buff);
	return (all);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	saved = ft_read(saved, fd);
	if (!saved)
		return (0);
	if (saved[0] == '\0')
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	line = cut(saved);
	saved = copy_to_xyata(saved);
	if (line[0] == '\n')
		free(saved);
	return (line);
}
