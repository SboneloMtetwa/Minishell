/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:13:36 by smtetwa           #+#    #+#             */
/*   Updated: 2018/06/05 14:36:24 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			n;
	long int	ans;
	long int	max;

	ans = 0;
	n = 1;
	max = 2147483648;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		n = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		ans = (ans * 10) + (*str - '0');
		if (ans > max && n == 1)
			return (-1);
		else if (ans > max && n == -1)
			return (0);
		str++;
	}
	return (ans * n);
}
