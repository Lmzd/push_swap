/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:33:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 20:28:46 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sort(t_stack *a, t_stack *b)
{
	t_lst *curr;

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
