/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:45:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 03:58:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	t_lst *first;
	t_lst *last;
	t_lst *sec;

	(void)b;
	if (a->nb_val < 2)
		return ;
	first = a->head;
	sec = first->next;
	last = a->foot;
	a->head = sec;
	a->foot = first;
	first->next = NULL;
	first->prev = last;
	sec->prev = NULL;
	last->next = first;
}

void	rotate_b(t_stack *a, t_stack *b)
{
	t_lst *first;
	t_lst *last;
	t_lst *sec;

	(void)a;
	if (b->nb_val < 2)
		return ;
	first = b->head;
	sec = first->next;
	last = b->foot;
	b->head = sec;
	b->foot = first;
	first->next = NULL;
	first->prev = last;
	sec->prev = NULL;
	last->next = first;
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}
