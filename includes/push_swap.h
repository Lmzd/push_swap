/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:27:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/30 19:20:05 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_lst
{
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	t_lst			*head;
	t_lst			*foot;
}					t_stack;

t_lst				*ft_create_lst(int *tab, int nb_val);
t_stack				*ft_create_stack(t_lst *begin);

#endif
