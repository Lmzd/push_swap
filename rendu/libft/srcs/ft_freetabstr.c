/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:10:39 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 20:38:40 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void	ft_freetabstr(char **tab, int nb)
{
	if (!tab)
		return ;
	while (--nb)
		free(tab[nb]);
	free(tab);
}
