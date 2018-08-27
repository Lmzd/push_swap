/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhas_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:23:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:03:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strhas_str(const char *str, const char *find)
{
	char	*src;
	int		i;
	int		j;
	int		f_len;

	i = 0;
	j = 0;
	f_len = 0;
	src = (char *)str;
	if (!(f_len = ft_strlen(find)))
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == find[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (j == f_len)
			return (1);
		i++;
	}
	return (0);
}
