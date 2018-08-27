/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:35:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 06:44:14 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutstr(char *src, int c)
{
	int		len;
	int		i;
	char	*cut;

	i = 0;
	len = 0;
	while (src[i++] != c)
		len++;
	if (!(cut = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len && src[i] != '\0')
	{
		cut[i] = src[i];
		i++;
	}
	cut[len] = '\0';
	return (cut);
}
