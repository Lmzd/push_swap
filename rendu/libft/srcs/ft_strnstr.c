/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:49:40 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/08 22:09:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		f_len;
	char		*src;

	i = 0;
	j = 0;
	f_len = 0;
	src = (char *)str;
	if (!(f_len = ft_strlen(to_find)))
		return (&src[0]);
	while (src[i] != '\0' && i < len)
	{
		if (src[i] == to_find[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (j == f_len)
			return (&src[i - j + 1]);
		i++;
	}
	return (0);
}
