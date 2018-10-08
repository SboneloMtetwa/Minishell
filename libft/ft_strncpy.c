/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:54:23 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/09 14:54:32 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ret;
	size_t	i;

	i = -1;
	ret = dst;
	while (++i < len)
	{
		if (*(src))
			*(dst++) = *(src++);
		else
			*(dst++) = 0;
	}
	return (ret);
}
