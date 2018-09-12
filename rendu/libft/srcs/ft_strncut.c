/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:32:26 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:01:27 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char **src, size_t n)
{
	size_t	i;
	char	*cut;

	i = 0;
	if (!(cut = (char *)malloc(sizeof(char) * n + 1)))
		return (0);
	while (i < n && **src != '\0')
	{
		cut[i] = **src;
		(*src)++;
		i++;
	}
	cut[n] = '\0';
	return (cut);
}
