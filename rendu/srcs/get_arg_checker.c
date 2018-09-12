/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:21:54 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 21:22:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern void	ft_check_one_arg(char *arg, int print)
{
	int		*tab;
	char	**arg0;
	t_lst	*begin;
	int		nb;

	arg0 = ft_strsplit(arg, ' ');
	if ((!ft_check_argv(arg0))
		|| !(tab = ft_check_double(ft_strtablen(arg0), arg0)))
		print_error();
	nb = ft_strtablen(arg0);
	if (nb == 1)
	{
		free(tab);
		exit(0);
	}
	tab = ft_check_double(nb, arg0);
	begin = ft_create_lst(tab, nb);
	normalization(tab, nb);
	checker(begin, tab, nb, print);
	exit(0);
}
