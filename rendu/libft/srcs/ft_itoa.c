/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:19:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_nb_len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	int		is_neg;
	int		nb_len;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	nb_len = ft_nb_len(n);
	if (!(res = ft_strnew(nb_len)))
		return (NULL);
	nb_len += is_neg;
	while (nb_len > is_neg)
	{
		res[nb_len-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
