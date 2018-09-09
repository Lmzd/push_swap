/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:53:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 04:49:45 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_get_min(t_lst *list)
{
	t_lst	*elem;
	int		min;

	elem = list;
	min = elem->n;
	while (elem)
	{
		if (elem->n < min)
			min = elem->n;
		elem = elem->next;
	}
	return (min);
}

int		ft_get_max(t_lst *list)
{
	t_lst	*elem;
	int		max;

	elem = list;
	max = elem->n;
	while (elem)
	{
		if (elem->n > max)
			max = elem->n;
		elem = elem->next;
	}
	return (max);
}

int		ft_get_med(t_lst *list, int nb_val)
{
	int		med;
	t_lst	*elem;
	int		odd;

	elem = list;
	odd = (nb_val % 2) ? 0 : 1;
	med = (nb_val + odd) / 2;
	while (elem)
	{
		if (elem->id == med)
			return (elem->n);

		elem = elem->next;
	}
	return (0);
}
