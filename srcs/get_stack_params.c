/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:53:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 02:44:34 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_get_min(t_lst *list)
{
	t_lst	*elem;
	int		min;

	elem = list;
	min = elem->data;
	while (elem)
	{
		if (elem->data < min)
			min = elem->data;
		elem = elem->next;
	}
	return (min);
}

int		ft_get_max(t_lst *list)
{
	t_lst	*elem;
	int		max;

	elem = list;
	max = elem->data;
	while (elem)
	{
		if (elem->data > max)
			max = elem->data;
		elem = elem->next;
	}
	return (max);
}

int		ft_get_med(t_lst *list, int nb_val)
{
	int		med;
	t_lst	*elem;

	elem = list;
	med = (nb_val + 1) / 2;
	while (elem)
	{
		if (elem->id == med)
			return (elem->data);

		elem = elem->next;
	}
	return (0);
}
