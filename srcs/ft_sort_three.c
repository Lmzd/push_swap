/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 06:19:06 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 06:23:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"

void	ft_sort_three_a(t_stack *a, t_stack *b, int sort_status)
{
	if (ft_check_sort(a, b, sort_status))
		return ;
	if (((a->foot->n > a->foot->prev->n) && (a->foot->n < a->head->n))
		|| (((a->head->n > a->head->next->n) && (a->head->n > a->foot->n))
		&& (a->foot->n < a->foot->prev->n)))
		rotate_a(a, b, 1);
	else if (((a->foot->n > a->head->n) && (a->foot->n < a->foot->prev->n))
		|| ((a->head->n < a->head->next->n) && (a->head->n > a->foot->n)))
		rotate_rev_a(a, b, 1);
	else if ((a->head->n > a->head->next->n) && (a->head->n < a->foot->n))
		swap_a(a, b, 1);
	ft_sort_three_a(a, b, sort_status);
}

void	ft_sort_three_b(t_stack *a, t_stack *b)
{
	if (ft_check_sort_b(a, b))
		return ;
	if (((b->head->n < b->head->next->n) && (b->head->n < b->foot->n)
		&& (b->foot->n > b->foot->prev->n))
		|| ((b->head->n < b->head->next->n) && (b->head->n < b->foot->n)
		&& (b->foot->n < b->foot->prev->n)))
		rotate_b(a, b, 1);
	else if (((b->head->n > b->head->next->n) && (b->head->n < b->foot->n))
		|| ((b->head->n > b->head->next->n) && (b->head->n > b->foot->n)
		&& (b->foot->n > b->foot->prev->n)))
		rotate_rev_b(a, b, 1);
	else if ((b->head->n < b->head->next->n) && (b->head->n > b->foot->n))
		swap_b(a, b, 1);
	ft_sort_three_b(a, b);
}
