/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:05:14 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 11:25:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"

int		get_iteratoin_number(int nb)
{
	if (nb <= 100)
		return (3);
	if (nb <= 300)
		return (5);
	if (nb <= 400)
		return (7);
	return (10);
}

int		ft_is_ra(t_brain *brain, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->head;
	while (elem && (elem->n < brain->min || elem->n > brain->max))
	{
		elem = elem->next;
		count++;
	}
	return (count);
}

int		ft_is_rra(t_brain *brain, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->foot;
	while (elem && (elem->n < brain->min || elem->n > brain->max))
	{
		elem = elem->prev;
		count++;
	}
	return (count);
}

int		ft_is_rb(t_brain *brain, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->head;
	count = 0;
	while (elem)
	{
		if (elem->n == brain->tab[brain->id])
			return (count);
		elem = elem->next;
		count++;
	}
	return (0);
}

int		ft_is_rrb(t_brain *brain, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->foot;
	count = 0;
	while (elem)
	{
		if (elem->n == brain->tab[brain->id])
			return (count);
		elem = elem->prev;
		count++;
	}
	return (0);
}
