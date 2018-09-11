/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:58:23 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 12:00:25 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	ft_sort(int *tab, int nb_val)
{
	int i;

	i = 0;
	while (i < nb_val - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static inline void	ft_swap(int *tab, int id, int *pivot, int nb_val)
{
	int tmp;

	if ((*pivot == nb_val) || ((*pivot - id) > 1))
	{
		tmp = tab[*pivot - 1];
		tab[*pivot - 1] = tab[*pivot];
		tab[*pivot] = tmp;
		(*pivot)--;
		tmp = tab[*pivot + 1];
		tab[*pivot + 1] = tab[id];
		tab[id] = tmp;
	}
	else
	{
		tmp = tab[*pivot];
		tab[*pivot] = tab[id];
		tab[id] = tmp;
	}
}

static inline void	quicksort(int *tab, int *pivot, int nb_val)
{
	int i;
	int tmp;

	if (ft_sort(tab, nb_val))
		return ;
	if (*pivot == -1)
		*pivot = nb_val - 1;
	i = 0;
	while (i < *pivot)
	{
		tmp = tab[i];
		if (tab[i] > tab[*pivot])
			ft_swap(tab, i, pivot, nb_val);
		if (tmp == tab[i])
			i++;
	}
	(*pivot)--;
	quicksort(tab, pivot, nb_val);
}

extern int			*normalization(int *tab, int nb_val)
{
	int	*pivot;

	if (!(pivot = (int*)malloc(sizeof(int))))
		return (0);
	*pivot = nb_val - 1;
	quicksort(tab, pivot, nb_val);
	free(pivot);
	return (tab);
}
