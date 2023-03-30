/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_nedeed_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:56:57 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/30 00:56:58 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr_fd(char *s, int fd)

{
	if (s)
		write(fd, s, ft_strlen(s));
}

int	counter(int c)
{
	int	count;

	count = 0;
	if (c == 0)
		count = count + 1;
	if (c < 0)
		count = count + 1;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

int	if_stuff(int n, char *str)
{
	unsigned int	nb;

	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	i = counter(n);
	str = malloc (i + 1 * sizeof(char));
	if (!str)
		return (0);
	nb = if_stuff(n, str);
	i--;
	while (nb != 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	i = counter(n);
	str[i] = '\0';
	return (str);
}
