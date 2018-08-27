/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:12:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		f_len;
	char	*src;

	i = 0;
	j = 0;
	f_len = 0;
	src = (char *)str;
	if (!(f_len = ft_strlen(to_find)))
		return (&src[0]);
	while (src[i] != '\0')
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
