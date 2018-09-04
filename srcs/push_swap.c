/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:43:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:19:26 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	int		*tab;
	t_lst	*begin;
	t_stack	*a_stack;

	if (argc > 2)
	{
		argv++;
		if ((!ft_check_argv(argv)) || (!ft_check_double(argc, argv)))
		{
			ft_printf("Error\n");
			exit(0);
		}
		tab = ft_check_double(argc, argv);
		begin = ft_create_lst(tab, argc - 1);
		normalization(tab, argc - 1);
		a_stack = ft_create_stack(begin, tab, argc - 1);
	}
	else
		ft_printf("Error\n");
}