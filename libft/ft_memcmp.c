/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:09:11 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/07 13:09:15 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte *x1;
	const t_byte *x2;

	x1 = s1;
	x2 = s2;
	while (n--)
		if (*x1 != *x2)
			return (*x1 - *x2);
		else
		{
			x1++;
			x2++;
		}
	return (0);
}
