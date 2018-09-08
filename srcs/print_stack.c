/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 02:41:25 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/06 20:23:40 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(const char *title, t_stack *stack)
{
	t_lst *elem;

	ft_printf("{red}---{def} {lmag}%s{def} {red}---{def}\n", title);
	if (stack->head == NULL)
	{
		ft_printf(" {lgreen}(null){def}\n");
		return ;
	}
	elem = stack->head;
	while (elem)
	{
		ft_printf(" {lgreen}%d{def} {lyellow}->{def}", elem->data);
		elem = elem->next;
	}
	ft_printf(" {lgreen}(null){def} {lred}⏩  ={def} {lcyan}%d{def}\
{lred} && ⏪  ={def}{lcyan} %d{def}\n", stack->head->data, stack->foot->data);
	ft_printf("{yellow}min :{def} {lmag}%d{def} | {yellow}max :{def} \
{lmag}%d{def} | {yellow}med :{def} {lmag}%d{def}", stack->min, 
	stack->max, stack->med);
	ft_printf("\n");
}
