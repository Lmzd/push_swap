/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:44:23 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/04 18:10:45 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		if (!(res = ft_strnew(len_s1 + len_s2)))
			return (NULL);
		ft_strcat(res, s1);
		ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
