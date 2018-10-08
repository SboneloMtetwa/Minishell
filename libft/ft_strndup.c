/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:24:00 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/07 13:24:08 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *memdup;

	if (!(memdup = ft_strnew(n)))
		return (NULL);
	ft_strncpy(memdup, s1, n);
	return (memdup);
}
