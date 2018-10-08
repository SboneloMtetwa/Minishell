/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:44:15 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/07 13:44:24 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	char *ret;

	if (!s || start + len > ft_strlen(s))
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	return (ft_strncpy(ret, s + start, len));
}
