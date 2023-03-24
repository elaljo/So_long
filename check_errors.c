/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:04:09 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/15 11:04:10 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_funcs(char *argv[], char **str, int fd)
{
	if (check_empty_map(fd) != 1)
		return (0);
	if (check_characters(str) != 1)
		return (0);
	if (check_max_characters(str) != 1)
		return (0);
	if (check_rows_walls(str) != 1)
		return (0);
	if (check_columns_walls(str) != 1)
		return (0);
	if (check_if_rectangular(str) != 1)
		return (0);
	if (check_ending_extension(argv) != 1)
		return (0);
	if (check_nl_inside(fd) != 1)
		return (0);
	if (check_nl_1st_last_line(fd) != 1)
		return (0);
	return (1);
}
