/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:45:16 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 19:44:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rev_a(t_stack *a, t_stack *b, int status)
{
	t_lst *first;
	t_lst *last;
	t_lst *next_to;

	(void)b;
	if (a->nb_val < 2)
		return ;
	first = a->head;
	last = a->foot;
	next_to = last->prev;
	a->head = last;
	a->foot = next_to;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	next_to->next = NULL;
	if (status)
		ft_printf("rra\n");
}

void	rotate_rev_b(t_stack *a, t_stack *b, int status)
{
	t_lst *first;
	t_lst *last;
	t_lst *next_to;

	(void)a;
	if (b->nb_val < 2)
		return ;
	first = b->head;
	last = b->foot;
	next_to = last->prev;
	b->head = last;
	b->foot = next_to;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	next_to->next = NULL;
	if (status)
		ft_printf("rrb\n");
}

void	rotate_rev_ab(t_stack *a, t_stack *b, int status)
{
	rotate_rev_a(a, b, 0);
	rotate_rev_b(a, b, 0);
	if (status)
		ft_printf("rrr\n");
}
