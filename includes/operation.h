/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:09:45 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/03 22:37:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			swap_a(t_stack *a, t_stack *b);
void			swap_b(t_stack *a, t_stack *b);
void			swap_ab(t_stack *a, t_stack *b);
void			rotate_a(t_stack *a, t_stack *b);
void			rotate_b(t_stack *a, t_stack *b);
void			rotate_ab(t_stack *a, t_stack *b);
void			rotate_rev_a(t_stack *a, t_stack *b);
void			rotate_rev_b(t_stack *a, t_stack *b);
void			rotate_rev_ab(t_stack *a, t_stack *b);

#endif
