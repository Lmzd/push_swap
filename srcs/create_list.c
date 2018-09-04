/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:12:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:22:54 by lmazeaud         ###   ########.fr       */
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

t_stack	*ft_create_stack(t_lst *begin, int *tab, int nb_val)
{
	t_lst	*elem;
	t_stack	*stack;
	int		i;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	elem = begin;
	stack->head = elem;
	stack->nb_val = nb_val;
	while (elem->next)
		elem = elem->next;
	stack->foot = elem;
	elem = begin;
	while (elem)
	{
		i = -1;
		while (++i < nb_val)
			if (tab[i] == elem->data)
				elem->id = i;
		elem = elem->next;
	}
	return (stack);
}

t_stack	*ft_init_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->foot = NULL;
	stack->head = NULL;
	stack->nb_val = 0;
	return (stack);
}
