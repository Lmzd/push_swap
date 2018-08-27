/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_intmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:19:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/05 02:19:56 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_nb_len_base(intmax_t n, int base)
{
	int len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char			*ft_itoa_base_intmax(intmax_t n, int base)
{
	int				is_neg;
	int				nb_len;
	char			*res;
	static char		str_charset[] = "0123456789abcdef";

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	nb_len = ft_nb_len_base(n, base);
	res = ft_strnew(nb_len);
	nb_len += is_neg;
	while (nb_len > is_neg)
	{
		res[nb_len-- - 1] = str_charset[(n % base)];
		n /= base;
	}
	res[0] = (is_neg) ? '-' : res[0];
	return (res);
}
