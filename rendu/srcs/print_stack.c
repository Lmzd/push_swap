/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 02:41:25 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 13:27:45 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(const char *title, t_stack *stack)
{
	t_lst *elem;

	ft_printf("{red}---{def} {lmag}%s{def} {red}---{def}\n", title);
	if (stack->head == NULL)
	{
		ft_printf(" {lyellow}(null){def}\n");
		return ;
	}
	elem = stack->head;
	while (elem)
	{
		ft_printf("{lcyan} %d{def}", elem->n);
		elem = elem->next;
	}
	ft_printf("\n");
}
