/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:43:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 20:34:56 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operation.h"

void	ft_sort_three(t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b))
		exit(0);
	if (a->head->id - a->head->next->id == 1)
		swap_a(a, b, 1);
	if ((a->head->id - a->foot->id) == 2)
		rotate_a(a, b, 1);
	else if ((a->head->id - a->foot->id) == 1 ||
	(a->head->id - a->foot->id) == -1)
		rotate_rev_a(a, b, 1);
	ft_sort_three(a, b);
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (a->nb_val <= 3)
		ft_sort_three(a, b);
	// else if (a->nb_val <= 6)
	// 	ft_sort_few(a, b);
	// else
	// 	ft_sort_all(a, b);
}

int		main(int argc, char **argv)
{
	int		*tab;
	t_lst	*begin;
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (--argc >= 2)
	{
		argv++;
		if ((!ft_check_argv(argv)) || (!ft_check_double(argc, argv)))
		{
			ft_printf("Error\n");
			exit(0);
		}
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc);
		normalization(tab, argc);
		a_stack = ft_create_stack(begin, tab, argc);
		b_stack = ft_init_stack();
		ft_sort_stack(a_stack, b_stack);
	}
	else
		ft_printf("Error\n");
}
