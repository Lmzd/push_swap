/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 05:28:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	len = i;
	if (size > 0)
		while (src[i - len] && i < size - 1)
		{
			dest[i] = src[i - len];
			i++;
		}
	if (len < size)
		dest[i] = '\0';
	return (len + ft_strlen(src));
}
