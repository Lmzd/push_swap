/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 04:25:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/04 04:29:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillit(char c, size_t n)
{
	char	*res;

	if (c < 32 || !n)
		return (0);
	res = ft_strnew(n);
	while (n--)
		res[n] = c;
	return (res);
}
