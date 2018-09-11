/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07:02:23 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/11 23:26:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**read_entry(void)
{
	char	*line;
	char	*result;
	char	*get_line;
	char	**entry;
	int		ret;

	ret = 1;
	result = ft_strnew(0);
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			get_line = ft_strjoin(result, line);
			free(line);
			free(result);
			result = ft_strjoin(get_line, "\n");
			free(get_line);
		}
	}
	entry = ft_strsplit(result, '\n');
	free(result);
	return (entry);
}
