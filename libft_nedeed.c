/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_nedeed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:55:36 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/11 16:55:38 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)

{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0');
	else
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
}
