/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:33:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 18:33:54 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sort(t_stack *a, t_stack *b)
{
	if (b->head != NULL)
		return (0);
	else
	{
		while (a->head->next)
		{
			if (a->head->data > a->head->next->data)
				return (0);
			a->head = a->head->next;
		}
		return (1);
	}
}
