/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:37:34 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/13 10:48:51 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*data;
	int		i;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	data = ft_strnew(ft_strlen(s));
	if (data == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		data[i] = f(s[i]);
	return (data);
}
