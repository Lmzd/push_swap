/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:12:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/31 13:58:12 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_lst(t_lst **begin, t_lst *curr)
{
	t_lst	*elem;

	elem = *begin;
	if (!elem)
	{
		*begin = curr;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	curr->prev = elem;
	elem->next = curr;
	curr->next = NULL;
}

t_lst	*ft_create_lst(int *tab, int nb_val)
{
	t_lst	*curr;
	t_lst	*begin;
	int		i;

	begin = NULL;
	i = 0;
	while (i < nb_val)
	{
		if (!(curr = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		curr->id = 0;
		curr->data = tab[i];
		curr->next = NULL;
		curr->prev = NULL;
		ft_add_lst(&begin, curr);
		i++;
	}
	return (begin);
}

t_stack	*ft_create_stack(t_lst *begin)
{
	t_lst	*elem;
	t_stack	*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	elem = begin;
	stack->head = elem;
	while (elem->next)
		elem = elem->next;
	stack->foot = elem;
	return (stack);
}
