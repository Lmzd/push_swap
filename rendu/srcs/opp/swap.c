/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:45:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 20:04:56 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *a, t_stack *b, int status)
{
	t_lst *first;
	t_lst *sec;
	t_lst *ter;

	(void)b;
	if (a->nb_val < 2)
		return ;
	first = a->head;
	sec = first->next;
	ter = (sec->next) ? sec->next : NULL;
	a->head = sec;
	if (a->nb_val == 2)
		a->foot = first;
	first->next = ter;
	first->prev = sec;
	sec->prev = NULL;
	sec->next = first;
	if (ter)
		ter->prev = first;
	if (status)
		ft_printf("sa\n");
}

void	swap_b(t_stack *a, t_stack *b, int status)
{
	t_lst *first;
	t_lst *sec;
	t_lst *ter;

	(void)a;
	if (b->nb_val < 2)
		return ;
	first = b->head;
	sec = first->next;
	ter = (b->head->next->next) ? b->head->next->next : NULL;
	b->head = sec;
	if (b->nb_val == 2)
		b->foot = first;
	first->next = ter;
	first->prev = sec;
	sec->prev = NULL;
	sec->next = first;
	if (ter)
		ter->prev = first;
	if (status)
		ft_printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b, int status)
{
	swap_a(a, b, 0);
	swap_b(a, b, 0);
	if (status)
		ft_printf("ss\n");
}
