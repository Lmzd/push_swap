/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 06:20:15 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 06:23:58 by lmazeaud         ###   ########.fr       */
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

void	push_to_a(t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b, 1))
		return ;
	push_a(a, b, 1);
	push_to_a(a, b);
}
