/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:48:50 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 21:38:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern void	ft_sort_one_arg(char *arg)
{
	int		*tab;
	char	**arg0;
	int		*tab_s;
	t_lst	*begin;
	int		nb;

	tab = NULL;
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
	begin = ft_create_lst(tab, nb);
	tab_s = normalization(tab, nb);
	ft_sort_main(tab_s, begin, nb);
	exit(0);
}
