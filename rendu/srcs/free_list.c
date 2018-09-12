/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:43:17 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 23:36:09 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_free(t_lst *curr)
{
	t_lst *tmp;

	while (curr)
	{
		tmp = curr;
		tmp->n = 0;
		tmp->id = 0;
		tmp->prev = NULL;
		curr = curr->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_free_tab(int *tab, int nb_val)
{
	int	*tmp;
	int	i;

	i = -1;
	while (++i < nb_val)
	{
		tmp = tab;
		tab++;
		tmp = NULL;
		free(tmp);
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->head)
		ft_lst_free(stack->head);
	free(stack);
}

void	free_list(t_brain *brain, t_stack *a, t_stack *b, int *tab)
{
	ft_free_tab(tab, a->nb_val);
	free(brain);
	free_stack(b);
	free_stack(a);
}
