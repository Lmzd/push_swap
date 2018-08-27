/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:09:03 by pblouin           #+#    #+#             */
/*   Updated: 2018/05/08 22:11:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_recursive_sqrt(int nb, int i)
{
	while (i <= (nb / 2) && i < 46341)
	{
		if (i * i == nb)
			return (i);
		return (ft_recursive_sqrt(nb, i + 1));
	}
	return (0);
}

int				ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_recursive_sqrt(nb, 1));
}
