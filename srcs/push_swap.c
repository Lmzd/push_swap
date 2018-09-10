/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:43:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/10 16:57:30 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_all(t_brain *brain, t_stack *a, t_stack *b)
{
	int nb_val;

	nb_val = a->nb_val;
	push_all_to_b(brain, a, b);
	// push_all_to_a(a, b, nb_val - 1);
}

void	sort_both(t_stack *a, t_stack *b)
{
	ft_sort_three_a(a, b, 0);
	ft_sort_three_b(a, b);
}

void	ft_sort_few(t_stack *a, t_stack *b)
{
	int		nb_val;

	if (ft_check_sort(a, b, 1))
		return ;
	nb_val = a->nb_val;
	push_to_b(a, b, (nb_val / 2));
	sort_both(a, b);
	push_to_a(a, b);
}

void	ft_sort_stack(t_brain *brain, t_stack *a, t_stack *b)
{
	if (a->nb_val <= 3)
		ft_sort_three_a(a, b, 1);
	else if (a->nb_val <= 6)
		ft_sort_few(a, b);
	else
		ft_sort_all(brain, a, b);
}

static void	ft_sort(int *tab_s, t_lst *begin, int nb_val)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_brain *brain;

	a_stack = ft_create_stack(begin, tab_s, nb_val);
	b_stack = ft_init_stack();
	brain = ft_init_brain(tab_s, a_stack);
	ft_sort_stack(brain, a_stack, b_stack);
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		*tab_s;
	t_lst	*begin;

	if (--argc >= 2)
	{
		argv++;
		if ((!ft_check_argv(argv)) || (!ft_check_double(argc, argv)))
		{
			ft_printf("Error1\n");
			exit(0);
		}
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc);
		tab_s = normalization(tab, argc);
		ft_sort(tab_s, begin, argc);
	}
	else
		ft_printf("Error0\n");
}
