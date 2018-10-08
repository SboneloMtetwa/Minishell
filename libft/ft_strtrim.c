/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:51:20 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/12 15:04:35 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		start;
	int		ending;
	int		x;

	if (s == NULL)
		return (NULL);
	x = -1;
	start = 0;
	ending = 0;
	while (ft_isspace(*(s + ++x)))
		start++;
	while (*(s + x++))
		if (ft_isspace(*(s + x - 1)))
			ending = ending + 1;
		else
			ending = 0;
	ret = ft_strnew(ft_strlen(s) - ending - start);
	if (ret == NULL)
		return (NULL);
	return (ft_strncpy(ret, s + start, ft_strlen(s) - ending - start));
}
