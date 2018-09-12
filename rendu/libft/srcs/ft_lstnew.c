/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:40:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/08 22:08:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(p->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	else
	{
		p->content = NULL;
		p->content_size = 0;
	}
	p->next = NULL;
	return (p);
}
