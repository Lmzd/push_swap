/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:34:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:43:43 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_argv(char **argv)
{
	int i;

	i = 0;
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

	i = -1;
	if (!(tab = (int*)malloc(sizeof(int) * argc)))
		return (0);
	while (argv[++i])
		tab[i] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc)
	{
		j = i;
		while (tab[++j])
			if (tab[i] == tab[j])
				return (0);
	}
	return (tab);
}
