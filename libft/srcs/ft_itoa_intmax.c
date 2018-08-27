/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:19:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/20 16:52:02 by lmazeaud         ###   ########.fr       */
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

char			*ft_itoa_intmax(intmax_t n)
{
	int		is_neg;
	int		nb_len;
	char	*res;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
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
