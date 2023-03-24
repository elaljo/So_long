/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:56:34 by moelalj           #+#    #+#             */
/*   Updated: 2023/03/03 14:59:18 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*mptr;
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	j = ft_strlen(str);
	if (start > j)
		return (ft_calloc(1, sizeof(char)));
	if (len >= j)
		return (ft_strdup (str + start));
	mptr = malloc(len + 1 * sizeof(char));
	if (!mptr)
		return (0);
	i = 0;
	while (i < len)
	{
		mptr[i] = str[start];
		i++;
		start++;
	}
	mptr[i] = '\0';
	return (mptr);
}

char	*ft_strdup(const char *str)
{
	size_t	l;
	char	*ptr;
	size_t	i;

	l = ft_strlen(str);
	ptr = (char *)malloc(l + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (! str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n > i)
	{
		str[i] = 0;
		i++;
	}
}
