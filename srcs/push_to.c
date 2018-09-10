/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 06:20:15 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/10 17:06:04 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"


void	push_to_b(t_stack *a, t_stack *b, int iteration)
{
	if (iteration == 0)
		return ;
	if (a->head->id < a->med)
	{
		push_b(a, b, 1);
		iteration--;
	}
	else if (a->head->next->id < a->med)
		rotate_a(a, b, 1);
	else if (a->foot->id < a->med)
		rotate_rev_a(a, b, 1);
	else
		rotate_a(a, b, 1);
	push_to_b(a, b, iteration);
}

void	order_b_stack(t_brain *brain, t_stack *a, t_stack *b)
{
	if (b->head->id < brain->med)
	{
		// ft_printf("\nmed: %d\n", brain->med);
		rotate_b(a, b, 1);
	}
}

void	do_rotate_a(t_brain *brain, t_stack *a, t_stack *b)
{
	// ft_printf("do_rotate_a\n");
	while (a->head && (a->head->n < brain->min || a->head->n > brain->max))
		rotate_a(a, b, 1);
}

void	do_rev_rotate_a(t_brain *brain, t_stack *a, t_stack *b)
{
	while (a->head && (a->head->n < brain->min || a->head->n > brain->max))
	{
		// ft_printf("head : %d < max: %d\n", a->head->n, brain->max);
		rotate_rev_a(a, b, 1);
	}
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

void	push_all_to_b(t_brain *brain, t_stack *a, t_stack *b)
{
	int i;
	int	f_ra;
	int f_rra;

	// ft_printf("nb_val : %d \n", a->nb_val);
	while (brain->index < 3)
	{
		ft_get_min(brain);
		ft_get_max(brain);
		ft_get_med_2(brain);
		// ft_printf("min: %d | max: %d | med: %d\n", brain->min, brain->max, brain->med);
		i = brain->loop;
		while (a->head && i--)
		{
			f_ra = ft_is_ra(brain, a);
			f_rra = ft_is_rra(brain, a);
			// ft_printf("f_ra: %d | f_rra: %d\n", f_ra, f_rra);
			(f_ra < f_rra) ? do_rotate_a(brain, a, b) : do_rev_rotate_a(brain, a, b);
			push_b(a, b, 1);
			brain->nb_val_a = a->nb_val;
			brain->nb_val_b = b->nb_val;
			order_b_stack(brain, a, b);
		}
		brain->index++;
	}
}

void	push_all_to_a(t_stack *a, t_stack *b, int id)
{
	if (ft_check_sort(a, b, 1))
		return ;
	if (b->head->id == id)
	{
		push_a(a, b, 1);
		id--;
	}
	else if (b->head->next->id == id)
		swap_b(a, b, 1);
	else if (b->foot->prev->id == id || b->foot->id == id)
		rotate_rev_b(a, b, 1);
	else if (b->head->n == b->min)
		rotate_b(a, b, 1);
	else
		rotate_b(a, b, 1);
	push_all_to_a(a, b, id);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b, 1))
		return ;
	push_a(a, b, 1);
	push_to_a(a, b);
}
