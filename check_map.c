/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:45:13 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/04 17:15:30 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == 'E') || (str[i][j] == 'P') ||
			(str[i][j] == 'C') || (str[i][j] == '1') || (str[i][j] == '0'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_max_characters(char **str)
{
	struct s_maxmembers	s;

	s.j = 0;
	s.i = 0;
	s.p = 0;
	s.c = 0;
	s.e = 0;
	while (str[s.i])
	{
		s.j = 0;
		while (str[s.i][s.j++])
		{
			if (str[s.i][s.j] == 'E')
				s.e++;
			else if (str[s.i][s.j] == 'P')
				s.p++;
			else if (str[s.i][s.j] == 'C')
				s.c++;
		}
		s.i++;
	}
	if ((s.e != 1) || (s.p != 1) || (s.c < 1))
		return (0);
	return (1);
}

int	check_rows_walls(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[0][j])
	{
		if (str[0][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_columns_walls(char **str)
{
	int	i;
	int	len_str;

	i = 0;
	while (str[i])
	{
		if (str[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	len_str = ft_strlen(str[i]);
	while (str[i])
	{
		if (str[i][len_str - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_rectangular(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[0]) != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}
