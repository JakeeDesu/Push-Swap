/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:09:20 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 11:08:36 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_memo
{
	int				type;
	void			*data;
	struct s_memo	*next;
}				t_memo;

typedef struct	s_elem
{
	t_memo			**memo;
	int				nb;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_info
{
	int			empty;
	int			l;
	int			la;
	int			lb;
	int			max;
	int			mid;
	int			min;
}				t_info;

typedef void	(*t_fun)(t_elem**, t_elem**);

typedef struct	s_inst
{
	t_memo			**memo;
	char			*name;
	t_fun			f;
	struct s_inst	*next;
}				t_inst;

int				is_dub(t_elem *stack);
void			search_elem_and_put_null(int nb, t_memo **memo);
void			*alloc_memo(size_t size, t_memo **memo, int type);
void			free_memo(t_memo **mem);
int				pop(t_elem **stack);
void			push(t_elem **stack, int n, t_memo **memo);
int				peek(t_elem *stack);
void			swap_stack(t_elem **stack, t_memo **memo);
void			free_stack(t_elem **stack);
void			show_stack(t_elem *stack);
int				valid_arg(char **argv);
void			sa(t_elem **a, t_elem **b);
void			sb(t_elem **a, t_elem **b);
void			ss(t_elem **a, t_elem **b);
void			pa(t_elem **a, t_elem **b);
void			pb(t_elem **a, t_elem **b);
void			ra(t_elem **a, t_elem **b);
void			rb(t_elem **a, t_elem **b);
void			rr(t_elem **a, t_elem **b);
void			rra(t_elem **a, t_elem **b);
void			rrb(t_elem **a, t_elem **b);
void			rrr(t_elem **a, t_elem **b);
char			*get_name(t_fun f, t_memo **memo);
t_fun			get_fun(char *name);
void			add_inst(t_inst **list, t_fun f, t_memo **memo);
void			free_inst_list(t_inst **list, char c);
void			show_instructions(t_inst *list);
void			get_min(t_elem *a, t_info *info);
int				tst_swap_b(t_elem *b);
int				tst_rot_b(t_elem *b, t_info info, int up);
t_inst			*gen_list(t_elem **a, t_elem **b, t_info info);
void			sort(t_inst **list, t_elem **a, t_elem **b, t_info info);
void			x_sort(t_inst **list, t_elem **a, t_elem **b, t_info info);
void			last_sort(t_inst **list, t_elem **a, t_elem **b, t_info info);
int				is_sorted(t_elem *a, t_info info);
t_info			get_info(t_elem *a, int length);
t_fun			make_decision(t_elem **a, t_elem **b, t_info *info);
void			show_info(t_info info, t_elem *a, t_elem *b, t_fun f);
void			apply_inst(t_inst *list, t_elem **stack, t_elem **stack2);
t_inst			*sort_3(t_elem **a);
t_inst			*sort_3p(t_elem **a);
t_inst			*sort_3b(t_elem **b);
t_inst			*sort_3pb(t_elem **b);
void			merge_inst(t_inst **list, t_inst **s_x, t_elem **a, t_elem **b);
void			add_and_apply(t_inst **list, t_elem **a, t_elem **b, t_fun f);
int				read_input(t_inst **list, t_memo **memo);
char			**split_shit(char const *s, char c, t_memo **memo);
void			free_tab(void **data);
int				fill_stack(t_elem **a, int argc, char **argv, t_memo **memo);
int				is_int(char *str);
void			fill_memo(t_memo *n_memo, t_memo **memo, void *data, int type);
int				is_separated(t_elem *a, t_elem *b, t_info info);
int				list_length(t_elem *l);
#endif
