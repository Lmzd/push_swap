/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:27:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 04:11:14 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

int		check_entry(char **entry)
{
	int i;
	int j;
	int nb_check;

	i = -1;
	nb_check = 0;
	while (entry[++i])
	{
		j = -1;
		while (g_opp[++j].define)
			if (!ft_strcmp(g_opp[j].define, entry[i]))
				nb_check++;
	}
	return (i == nb_check) ? 1 : 0;
}

void	ft_route_opp(char **entry, t_stack *a, t_stack *b, int print)
{
	int i;
	int j;

	i = -1;
	while (entry[++i])
	{
		j = -1;
		while (g_opp[++j].define)
		{
			if (!ft_strcmp(entry[i], g_opp[j].define))
			{
				g_opp[j].f(a, b, 0);
				if (print)
				{
					ft_printf("{lblue}%s{def} :\n", entry[i]);
					ft_print_stack("stack a", a);
					ft_print_stack("stack b", b);
					ft_printf("\n");
				}
			}
		}
	}
}

void	checker(t_lst *begin, int *tab, int argc, int print)
{
	t_stack *a_stack;
	t_stack *b_stack;
	char	**entry;

	a_stack = ft_create_stack(begin, tab, argc);
	b_stack = ft_init_stack();
	entry = read_entry();
	if (!check_entry(entry))
		ft_printf("Error\n");
	ft_route_opp(entry, a_stack, b_stack, print);
	(ft_check_sort(a_stack, b_stack, 1)) ? ft_printf("{lgreen}OK{def}\n")
		: ft_printf("{lred}KO{def}\n");
}

int		main(int argc, char **argv)
{
	int		*tab;
	t_lst	*begin;
	int		print;

	if (--argc > 2)
	{
		argv++;
		print = (!ft_strcmp(argv[0], "-v")) ? 1 : 0;
		if (!ft_strcmp(argv[0], "-v"))
		{
			argv++;
			argc--;
		}
		if ((!ft_check_argv(argv)) || (!ft_check_double(argc, argv)))
		{
			ft_printf("Error\n");
			exit(0);
		}
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc);
		normalization(tab, argc);
		checker(begin, tab, argc, print);
	}
	else
		ft_printf("Error\n");
}
