/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:27:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/09 06:21:52 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_lst
{
	int				n;
	int				id;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	t_lst			*head;
	t_lst			*foot;
	int				max;
	int				min;
	int				med;
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
int					ft_check_sort(t_stack *a, t_stack *b, int sort_status);
int					ft_check_sort_b(t_stack *a, t_stack *b);
int					ft_get_med(t_lst *list, int nb_val);
int					ft_get_max(t_lst *list);
int					ft_get_min(t_lst *list);
void				ft_sort_three_b(t_stack *a, t_stack *b);
void				ft_sort_three_a(t_stack *a, t_stack *b, int sort_status);
void				push_to_b(t_stack *a, t_stack *b, int iteration);
void				push_to_a(t_stack *a, t_stack *b);

#endif
