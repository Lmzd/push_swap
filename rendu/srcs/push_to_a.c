/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:21:21 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 13:01:29 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"

void	do_rotate_b(t_brain *brain, t_stack *a, t_stack *b)
{
	while (b->head && b->head->n != brain->tab[brain->id])
	{
		if (brain->id > 0 && b->head->n == brain->tab[brain->id - 1])
		{
			push_a(a, b, 1);
			brain->mov_1 = 1;
		}
		else if (brain->id > 1 && brain->mov_1
			&& b->head->n == brain->tab[brain->id - 2])
		{
			push_a(a, b, 1);
			rotate_a(a, b, 1);
			brain->mov_2 = 1;
		}
		else
			rotate_b(a, b, 1);
	}
}

void	do_rev_rotate_b(t_brain *brain, t_stack *a, t_stack *b)
{
	while (b->head && b->head->n != brain->tab[brain->id])
	{
		if (brain->id > 0 && b->head->n == brain->tab[brain->id - 1])
		{
			push_a(a, b, 1);
			brain->mov_1 = 1;
		}
		else if (brain->id > 1 && brain->mov_1 &&
			b->head->n == brain->tab[brain->id - 2])
		{
			push_a(a, b, 1);
			rotate_a(a, b, 1);
			brain->mov_2 = 1;
		}
		else
			rotate_rev_b(a, b, 1);
	}
}

void	ft_check_move(t_brain *brain, t_stack *a, t_stack *b)
{
	if (brain->mov_1)
	{
		swap_a(a, b, 1);
		brain->id--;
		brain->mov_1 = 0;
	}
	if (brain->mov_2)
	{
		rotate_rev_a(a, b, 1);
		brain->id--;
		brain->mov_2 = 0;
	}
}

void	push_all_to_a(t_brain *brain, t_stack *a, t_stack *b)
{
	brain->id = b->nb_val - 1;
	while (b->head)
	{
		(ft_is_rb(brain, b) < ft_is_rrb(brain, b))
			? do_rotate_b(brain, a, b)
			: do_rev_rotate_b(brain, a, b);
		push_a(a, b, 1);
		ft_check_move(brain, a, b);
		brain->id -= 1;
	}
	if (a->foot->n < a->foot->prev->n)
	{
		rotate_rev_a(a, b, 1);
		rotate_rev_a(a, b, 1);
		swap_a(a, b, 1);
		rotate_a(a, b, 1);
		rotate_a(a, b, 1);
	}
}

void	push_to_a(t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b, 1))
		return ;
	push_a(a, b, 1);
	push_to_a(a, b);
}
