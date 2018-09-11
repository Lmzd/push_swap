/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 06:20:15 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 13:01:21 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"

void	push_to_b(t_stack *a, t_stack *b, int iteration)
{
	if (iteration == 0)
		return ;
	if (a->head->n < a->med)
	{
		push_b(a, b, 1);
		iteration--;
	}
	else if (a->head->next->n < a->med)
		rotate_a(a, b, 1);
	else if (a->foot->n < a->med)
		rotate_rev_a(a, b, 1);
	else
		rotate_a(a, b, 1);
	push_to_b(a, b, iteration);
}

void	do_rotate_a(t_brain *brain, t_stack *a, t_stack *b)
{
	while (a->head && (a->head->n < brain->min || a->head->n > brain->max))
		rotate_a(a, b, 1);
}

void	do_rev_rotate_a(t_brain *brain, t_stack *a, t_stack *b)
{
	while (a->head && (a->head->n < brain->min || a->head->n > brain->max))
		rotate_rev_a(a, b, 1);
}

void	push_all_to_b(t_brain *brain, t_stack *a, t_stack *b)
{
	int i;

	while (brain->index < brain->iteration)
	{
		ft_get_min(brain);
		ft_get_max(brain);
		ft_get_med_2(brain);
		i = brain->loop;
		while (a->head && i--)
		{
			(ft_is_ra(brain, a) < ft_is_rra(brain, a))
				? do_rotate_a(brain, a, b)
				: do_rev_rotate_a(brain, a, b);
			push_b(a, b, 1);
			if (b->head->id < brain->med)
				rotate_b(a, b, 1);
		}
		brain->index++;
	}
}
