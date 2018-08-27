/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 23:30:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (n == 0)
		return (dest);
	s = (char *)src;
	d = (char *)dest;
	while (--n)
		*(d++) = *(s++);
	*d = *s;
	return (dest);
}
