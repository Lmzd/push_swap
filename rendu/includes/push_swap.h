/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:27:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/12 21:17:07 by lmazeaud         ###   ########.fr       */
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
	int				moy;
	int				nb_val;
}					t_stack;

typedef struct		s_brain
{
	int				index;
	int				loop;
	int				mov_1;
	int				mov_2;
	int				id;
	int				min;
	int				max;
	int				med;
	int				*tab;
	int				iteration;
}					t_brain;

void				checker(t_lst *begin, int *tab, int argc, int print);
extern int			ft_check_argv(char **argv);
extern int			*ft_check_double(int argc, char **argv);
extern void			print_error(void);
extern int			ft_strtablen(char **tab);
t_lst				*ft_create_lst(int *tab, int nb_val);
t_stack				*ft_init_stack(void);
t_stack				*ft_create_stack(t_lst *begin, int *tab, int nb_val);
void				ft_init_stack_params(t_stack *stack);
extern int			*normalization(int	*tab, int nb_val);
void				ft_print_stack(const char *title, t_stack *stack);
char				**read_entry(void);
int					ft_check_sort(t_stack *a, t_stack *b, int sort_status);
int					ft_check_sort_b(t_stack *a, t_stack *b);
int					ft_get_med(t_lst *list, int nb_val);
void				ft_get_med_2(t_brain *brain);
void				ft_get_max(t_brain *brain);
void				ft_get_min(t_brain *brain);
void				ft_sort_three_b(t_stack *a, t_stack *b);
void				ft_sort_three_a(t_stack *a, t_stack *b, int sort_status);
void				push_to_b(t_stack *a, t_stack *b, int iteration);
void				push_to_a(t_stack *a, t_stack *b);
void				push_all_to_b(t_brain *brain, t_stack *a, t_stack *b);
void				push_all_to_a(t_brain *brain, t_stack *a, t_stack *b);
t_brain				*ft_init_brain(int *tab_s, t_stack *a);
int					get_iteratoin_number(int nb);
int					ft_is_ra(t_brain *brain, t_stack *a);
int					ft_is_rra(t_brain *brain, t_stack *a);
int					ft_is_rb(t_brain *brain, t_stack *b);
int					ft_is_rrb(t_brain *brain, t_stack *b);
void				free_list(t_brain *brain, t_stack *a, t_stack *b, int *tab);
void				free_stack(t_stack *stack);
extern void			ft_sort_one_arg(char *arg);
extern void			ft_check_one_arg(char *arg, int print);
void				ft_sort_main(int *tab_s, t_lst *begin, int nb_val);

#endif
