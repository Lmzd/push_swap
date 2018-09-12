/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:02 by pblouin           #+#    #+#             */
/*   Updated: 2018/08/05 04:41:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, int letter, size_t index)
{
	size_t len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (index > len - 1)
		return (NULL);
	str[index] = letter;
	return (str);
}
