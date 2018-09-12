/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:53:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/10 21:15:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_min(t_brain *brain)
{
	int		index;

	index = brain->index * brain->loop;
	(!brain->index) ? index : index--;
	brain->min = brain->tab[brain->index * brain->loop];
}

void	ft_get_max(t_brain *brain)
{
	int index;

	index = (brain->index + 1) * brain->loop;
	brain->max = brain->tab[--index];
}

void	ft_get_med_2(t_brain *brain)
{
	int offset;
	int	index;

	offset = (!brain->index) ? 0 : brain->loop / 2;
	index = (((brain->index + 1) * brain->loop) / 2) + (offset * brain->index);
	brain->med = brain->tab[--index];
}

int		ft_get_med(t_lst *list, int nb_val)
{
	int		med;
	t_lst	*elem;
	int		odd;

	if (!list)
		return (0);
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

void	ft_init_stack_params(t_stack *stack)
{
	stack->med = ft_get_med(stack->head, stack->nb_val);
}
