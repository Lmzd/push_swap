/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:04:38 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 18:48:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			is_neg;
	long long	number;

	i = 0;
	is_neg = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	is_neg = (str[i] == '-') ? 1 : is_neg;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
		if ((is_neg && number > 2147483648) || (!is_neg && number > 2147483647))
		{
			ft_putstr("Error\n");
			exit(0);
		}
	}
	return ((is_neg) ? -number : number);
}
