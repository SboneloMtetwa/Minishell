/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:24:08 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/11 13:24:49 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(int n)
{
	size_t			len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	number;

	len = get_num_len(n);
	number = n;
	if (n < 0)
	{
		number = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = number % 10 + '0';
	while (number /= 10)
		s[--len] = number % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
