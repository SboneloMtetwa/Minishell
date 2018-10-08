/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:38:52 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/13 11:37:26 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*data;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	data = ft_strnew(ft_strlen(s));
	if (data == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		data[i] = f(i, s[i]);
	return (data);
}
