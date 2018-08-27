/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:48:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 04:50:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char **src, int c)
{
	int		len;
	int		i;
	int		eol;
	char	*cut;

	i = 0;
	len = 0;
	eol = 0;
	(void)c;
	while ((*src)[i] != '\0' && (*src)[i++] != c)
		len++;
	cut = ft_strnew(len);
	i = 0;
	while (i < len && **src != '\0')
	{
		cut[i] = **src;
		(*src)++;
		i++;
	}
	if (**src != '\0')
		(*src)++;
	return (cut);
}
