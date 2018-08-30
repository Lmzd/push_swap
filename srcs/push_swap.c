/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:43:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/30 19:13:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_argv(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_str_is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int		*ft_check_double(int argc, char **argv)
{
	int *tab;
	int i;
	int j;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (0);
	while (argv[++i])
		tab[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (tab[++j])
			if (tab[i] == tab[j])
				return (0);
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	int		*tab;
	t_lst	*begin;
	t_stack	*a_stack;

	if (argc > 2)
	{
		if (!ft_check_argv(argv))
			ft_printf("error\n");
		if (!ft_check_double(argc, argv))
			ft_printf("error\n");
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc - 1);
		a_stack = ft_create_stack(begin);
	}
	else
		ft_printf("error\n");
}
