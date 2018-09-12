/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:33:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 04:21:11 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sort(t_stack *a, t_stack *b, int sort_status)
{
	t_lst *curr;

	if (sort_status)
		if (b->head != NULL)
			return (0);
	curr = a->head;
	while (curr->next)
	{
		if (curr->id > curr->next->id)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	ft_check_sort_b(t_stack *a, t_stack *b)
{
	t_lst *curr;

	(void)a;
	curr = b->head;
	while (curr->next)
	{
		if (curr->id < curr->next->id)
			return (0);
		curr = curr->next;
	}
	return (1);
}
