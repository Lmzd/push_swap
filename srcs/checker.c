/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:27:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 10:43:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

static inline void init_opps(t_opp opp[12])
{

	ft_strcpy(opp[0].define, PUSH_A);
	ft_strcpy(opp[1].define, PUSH_B);
	ft_strcpy(opp[2].define, SWAP_A);
	ft_strcpy(opp[3].define, SWAP_B);
	ft_strcpy(opp[4].define, SWAP_AB);
	ft_strcpy(opp[5].define, ROTATE_A);
	ft_strcpy(opp[6].define, ROTATE_B);
	ft_strcpy(opp[7].define, ROTATE_AB);
	ft_strcpy(opp[8].define, ROTATE_REV_A);
	ft_strcpy(opp[9].define, ROTATE_REV_B);
	ft_strcpy(opp[10].define, ROTATE_REV_AB);
	opp[11].define = 0;
	opp[0].f = &push_a;
	opp[1].f = &push_b;
	opp[2].f = &swap_a;
	opp[3].f = &swap_b;
	opp[4].f = &swap_ab;
	opp[5].f = &rotate_a;
	opp[6].f = &rotate_b;
	opp[7].f = &rotate_ab;
	opp[8].f = &rotate_rev_a;
	opp[9].f = &rotate_rev_b;
	opp[10].f = &rotate_rev_ab;
	opp[11].f = 0;
}

int check_entry(char **entry)
{
	int i;
	int j;
	int nb_check;
	t_opp opp[12];

	i = -1;
	nb_check = 0;
	init_opps(opp);
	while (entry[++i])
	{
		j = -1;
		while (opp[++j].define)
			if (!ft_strcmp(opp[j].define, entry[i]))
				nb_check++;
	}
	return ((i == nb_check) ? 1 : 0);
}

void ft_route_opp(char **entry, t_stack *a, t_stack *b, int print)
{
	int i;
	int j;
	t_opp opp[12];

	i = -1;
	init_opps(opp);
	while (entry[++i])
	{
		j = -1;
		while (opp[++j].define)
		{
			if (!ft_strcmp(entry[i], opp[j].define))
			{
				opp[j].f(a, b, 0);
				if (print)
				{
					ft_printf("{lgreen}%s :{def}\n", entry[i]);
					ft_print_stack("stack a", a);
					ft_print_stack("stack b", b);
					ft_printf("\n");
					ft_init_stack_params(a);
					ft_init_stack_params(b);
				}
				free(entry[i]);
			}
		}
	}
	free(entry);
}

void checker(t_lst *begin, int *tab, int argc, int print)
{
	t_stack *a_stack;
	t_stack *b_stack;
	char **entry;

	a_stack = ft_create_stack(begin, tab, argc);
	b_stack = ft_init_stack();
	entry = read_entry();
	if (!check_entry(entry))
		ft_printf("Error\n");
	ft_route_opp(entry, a_stack, b_stack, print);
	(ft_check_sort(a_stack, b_stack, 1)) ? ft_printf("OK\n")
										 : ft_printf("KO\n");
	free_stack(a_stack);
	free_stack(b_stack);
	free(tab);
}

int main(int argc, char **argv)
{
	int *tab;
	t_lst *begin;
	int *tab_1;
	int print;

	if (--argc > 2)
	{
		argv++;
		print = (!ft_strcmp(argv[0], "-v")) ? 1 : 0;
		if (!ft_strcmp(argv[0], "-v"))
		{
			argv++;
			argc--;
		}
		if ((!ft_check_argv(argv)) || !(tab_1 = ft_check_double(argc, argv)))
		{
			ft_printf("Error\n");
			exit(0);
		}
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc);
		normalization(tab, argc);
		checker(begin, tab, argc, print);
		free(tab_1);
	}
	else
		ft_printf("Error\n");
}
