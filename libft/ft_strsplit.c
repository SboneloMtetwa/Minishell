/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:45:42 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/13 14:26:17 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_word(const char *str, int i, char **ret, char c)
{
	int		length;
	int		sp;

	sp = 0;
	length = 0;
	while (*str == c)
	{
		str++;
		sp++;
	}
	while (str[length] && str[length] != c)
		length++;
	if (length > 0)
	{
		ret[i] = ft_strnew(length);
		ft_strncpy(ret[i], str, length);
	}
	return (sp + length);
}

static int		ft_wordcount(const char *str, int i, char c)
{
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		length;
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = ft_wordcount(s, 0, c);
	length = 0;
	ret = (char **)ft_memalloc((j + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	length = 0;
	while (*s)
	{
		length = ft_find_word(s, i++, ret, c);
		s += length;
	}
	ret[j] = 0;
	return (ret);
}
