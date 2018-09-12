/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:34:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 22:36:27 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

extern int	ft_check_argv(char **argv)
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

extern int	*ft_check_double(int argc, char **argv)
{
	int *tab;
	int i;
	int j;

	i = -1;
	if (!(tab = (int*)malloc(sizeof(int) * argc)))
		return (0);
	while (argv[++i])
		tab[i] = ft_atoi(argv[i]);
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

extern void	print_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

extern int	ft_strtablen(char **tab)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while (tab[++i])
		len++;
	return (len);
}
