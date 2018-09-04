/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07:02:23 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:34:49 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**read_entry(void)
{
	char	*line;
	char	*result;
	char	**entry;
	int		ret;

	result = ft_strnew(1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			result = ft_strjoin(result, line);
			result = ft_strjoin(result, "\n");
		}
	}
	entry = ft_strsplit(result, '\n');
	return (entry);
}
