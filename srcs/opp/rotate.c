/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:45:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 18:55:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a, t_stack *b, int status)
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
	if (status)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *a, t_stack *b, int status)
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
	if (status)
		ft_printf("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b, int status)
{
	rotate_a(a, b);
	rotate_b(a, b);
	if (status)
		ft_printf("rr\n");
}
