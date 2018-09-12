/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:28:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 09:01:35 by lmazeaud         ###   ########.fr       */
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
	void		(*f)(t_stack *, t_stack *, int);
}				t_opp;

#endif
