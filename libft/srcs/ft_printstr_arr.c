/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:22:02 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstr_arr(const char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putstr((char *)arr[i]);
		i++;
	}
}
