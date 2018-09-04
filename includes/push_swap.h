/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:27:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/04 07:07:19 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_lst
{
	int				data;
	int				id;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	t_lst			*head;
	t_lst			*foot;
	int				nb_val;
}					t_stack;

int					ft_check_argv(char **argv);
int					*ft_check_double(int argc, char **argv);
t_lst				*ft_create_lst(int *tab, int nb_val);
t_stack				*ft_init_stack(void);
t_stack				*ft_create_stack(t_lst *begin, int *tab, int nb_val);
int					*normalization(int	*tab, int nb_val);
void				ft_print_stack(const char *title, t_stack *stack);
char				**read_entry(void);
int					check_entry(char **entry);
void				ft_route_opp(char **entry, t_stack *a, t_stack *b,
				int print);

#endif
