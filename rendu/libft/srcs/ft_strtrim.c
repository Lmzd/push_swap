/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:54:04 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_trim(const char *s)
{
	unsigned int i;

	i = 0;
	while (ft_isblanks(s[i]))
		i++;
	return (i);
}

unsigned int	ft_trim_rev(const char *s)
{
	unsigned int i;

	i = ft_strlen(s) - 1;
	while (ft_isblanks(s[i]))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	begin;
	unsigned int	end;
	unsigned int	i;

	i = 0;
	if (s)
	{
		begin = ft_trim(s);
		if (s[begin] == '\0')
			return (ft_strnew(0));
		end = ft_trim_rev(s);
		res = ft_strsub(s, begin, (size_t)(end - begin + 1));
		return (res);
	}
	return (ft_strnew(0));
}
