/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:44:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 18:55:47 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a_helper(t_stack *a, t_stack *b, t_lst *tmp)
{
	tmp->next = a->head;
	a->head->prev = tmp;
	tmp->prev = NULL;
	a->head = tmp;
	b->foot = NULL;
	b->head = NULL;
}

void	push_a(t_stack *a, t_stack *b, int status)
{
	t_lst *tmp;

	if (!b->head)
		return ;
	tmp = b->head;
	b->head = tmp->next;
	if (!a->head && !a->foot)
	{
		tmp->next = NULL;
		a->head = tmp;
		a->foot = tmp;
	}
	else if (b->nb_val == 1)
		push_a_helper(a, b, tmp);
	else
	{
		tmp->next = a->head;
		a->head->prev = tmp;
		tmp->prev = NULL;
		a->head = tmp;
	}
	if (status)
		ft_printf("pa\n");
	a->nb_val++;
	b->nb_val--;
}

void	push_b_helper(t_stack *a, t_stack *b, t_lst *tmp)
{
	tmp->next = b->head;
	b->head->prev = tmp;
	tmp->prev = NULL;
	b->head = tmp;
	a->foot = NULL;
	a->head = NULL;
}

void	push_b(t_stack *a, t_stack *b, int status)
{
	t_lst *tmp;

	if (!a->head)
		return ;
	tmp = a->head;
	a->head = tmp->next;
	if (!b->head && !b->foot)
	{
		tmp->next = NULL;
		b->head = tmp;
		b->foot = tmp;
	}
	else if (a->nb_val == 1)
		push_b_helper(a, b, tmp);
	else
	{
		tmp->next = b->head;
		b->head->prev = tmp;
		tmp->prev = NULL;
		b->head = tmp;
	}
	if (status)
		ft_printf("pb\n");
	a->nb_val--;
	b->nb_val++;
}
