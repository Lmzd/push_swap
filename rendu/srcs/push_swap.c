/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:43:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 22:37:17 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline void	ft_sort_all(t_brain *brain, t_stack *a, t_stack *b)
{
	int nb_val;

	nb_val = a->nb_val;
	push_all_to_b(brain, a, b);
	push_all_to_a(brain, a, b);
}

static inline void	ft_sort_few(t_stack *a, t_stack *b)
{
	int		nb_val;

	if (ft_check_sort(a, b, 1))
		return ;
	nb_val = a->nb_val;
	push_to_b(a, b, (nb_val / 2));
	ft_sort_three_a(a, b, 0);
	ft_sort_three_b(a, b);
	push_to_a(a, b);
}

static inline void	ft_sort_stack(t_brain *brain, t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b, 1))
		return ;
	if (a->nb_val <= 3)
		ft_sort_three_a(a, b, 1);
	else if (a->nb_val <= 6)
		ft_sort_few(a, b);
	else
		ft_sort_all(brain, a, b);
}

void				ft_sort_main(int *tab_s, t_lst *begin, int nb_val)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_brain *brain;

	a_stack = ft_create_stack(begin, tab_s, nb_val);
	b_stack = ft_init_stack();
	brain = ft_init_brain(tab_s, a_stack);
	ft_sort_stack(brain, a_stack, b_stack);
	free_list(brain, a_stack, b_stack, tab_s);
}

int					main(int argc, char **argv)
{
	int		*tab;
	int		*tab_s;
	t_lst	*begin;

	tab = NULL;
	if (--argc >= 1)
	{
		argv++;
		if (ft_strhas_char(argv[0], ' '))
			ft_sort_one_arg(argv[0]);
		if ((!ft_check_argv(argv)) || !(tab = ft_check_double(argc, argv)))
			print_error();
		begin = ft_create_lst(tab, argc);
		tab_s = normalization(tab, argc);
		ft_sort_main(tab_s, begin, argc);
		free(tab);
	}
	return (0);
}
