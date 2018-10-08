/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:41:25 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/07 13:41:33 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	size_t n;

	n = ft_strlen(small);
	if (!*small)
		return ((char *)big);
	while (*big)
		if (!ft_memcmp(big++, small, n))
			return ((char *)big - 1);
	return (0);
}
