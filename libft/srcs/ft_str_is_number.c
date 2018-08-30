/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:57:54 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/29 18:55:56 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(const char *str)
{
	int i;
	int	start;

	i = 0;
	start = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[0] == '-' || str[0] == '+') && !start)
		{
			i++;
			start = 1;
		}
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}
