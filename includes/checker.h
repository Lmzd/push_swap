/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:28:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:05:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "operation.h"

# define PUSH_A "pa"
# define PUSH_B "pb"
# define SWAP_A	"sa"
# define SWAP_B "sb"
# define SWAP_AB "ss"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_AB "rr"
# define ROTATE_REV_A "rra"
# define ROTATE_REV_B "rrb"
# define ROTATE_REV_AB "rrr"

typedef struct	s_opp
{
	char		*define;
	void		(*f)(t_stack *, t_stack *);
}				t_opp;

t_opp			g_opp[] =
{
	{PUSH_A, &push_a},
	{PUSH_B, &push_b},
	{SWAP_A, &swap_a},
	{SWAP_B, &swap_b},
	{SWAP_AB, &swap_ab},
	{ROTATE_A, &rotate_a},
	{ROTATE_B, &rotate_b},
	{ROTATE_AB, &rotate_ab},
	{ROTATE_REV_A, &rotate_rev_a},
	{ROTATE_REV_B, &rotate_rev_b},
	{ROTATE_REV_AB, &rotate_rev_ab},
	{0, 0}
};

#endif
