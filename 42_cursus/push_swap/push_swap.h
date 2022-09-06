/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:32 by zzankor           #+#    #+#             */
/*   Updated: 2022/08/05 22:23:32 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*a_top;
	t_node	*a_bot;
	int		a_size;
	t_node	*b_top;
	t_node	*b_bot;
	int		b_size;
}				t_stack;

typedef struct s_loc
{
	int	tmp_a;
	int	tmp_b;
	int	real_a;
	int	real_b;
	int	min_a;
	int	min_b;
	int	max_a;
	int	max_b;
}				t_loc;

typedef struct s_pivot
{
	int	big;
	int	small;
}				t_pivot;

/////////////// sort_array.c ///////////////
void		ps_bubble_sort(int *array, int array_size);
t_pivot		ps_make_pivot(int *array, int array_size);

/////////////// error.c ///////////////
void		ps_print_error(char *message);
void		ps_free_stack(t_stack *stack);

////////////////// make_array.c //////////////////
int			ps_check_array_size(char **av, int ac);
int			*ps_make_array(char **av, int ac, int *array, int array_size);

////////////////// check_array.c //////////////////
void		ps_check_duplicate(int *array, int array_size);
int			ps_check_limit(char *word);
long long	ps_atoi_ll(char *str);
int			ps_str_check_from_n(char *str, int n);

////////////////// make_stack.c //////////////////
t_node		*ps_make_new_node(void);
t_stack		*ps_get_stack(t_stack *stack);
t_stack		*ps_array_to_stack(int *array, int array_size, t_stack *stack);

////////////////// sort.c //////////////////
void		ps_sort(t_stack *stack, int *array, int array_size);
void		ps_sort_three_arg(t_node *node, t_stack *stack);
void		ps_sort_five_arg(t_stack *stack, int *array);

////////////////// sort_over_3.c //////////////////
void		ps_sort_over_three(t_stack *stack);
void		ps_sort_last(t_stack *stack, t_loc *loc);

////////////////// sort_utils.c //////////////////
void		ps_node_to_stack_3_way(int *array, int array_size, t_stack *stack);
t_stack		*ps_move_node_3_way(t_pivot *pivot, t_stack *stack);

////////////////// sort_move.c //////////////////
void		ps_sort_move(t_stack *stack, t_loc *loc);
void		ps_sort_move_a(t_stack *stack, t_loc *loc);
void		ps_sort_move_b(t_stack *stack, t_loc *loc);
void		ps_sort_move_same(t_stack *stack, t_loc *loc);

////////////////// oper_s.c //////////////////
void		ps_sa(t_stack *stack);
void		ps_sb(t_stack *stack);

////////////////// oper_p.c //////////////////
void		ps_pa(t_stack *stack);
void		ps_pb(t_stack *stack);
void		ps_resize_p(t_stack *stack, char checker);

////////////////// oper_r.c //////////////////
void		ps_ra(t_stack *stack);
void		ps_rb(t_stack *stack);
void		ps_rr(t_stack *stack);

////////////////// oper_rr.c //////////////////
void		ps_rra(t_stack *stack);
void		ps_rrb(t_stack *stack);
void		ps_rrr(t_stack *stack);

////////////////// rea_loc.c //////////////////
void		ps_make_real_loc(t_stack *stack, t_loc *loc);
void		ps_make_a_idx(t_stack *stack, t_loc *loc, int b_num);
void		ps_make_a_idx_min_max(t_stack *stack, t_loc *loc, char *max_or_min);
void		ps_make_a_idx_mid(t_stack *stack, t_loc *loc, int b_num);
int			ps_change_to_small(t_loc *loc, int idx);
////////////////// rea_loc_utils.c //////////////////
t_loc		ps_loc_cpy(t_loc *loc);

////////////////// get_min_max.c //////////////////
int			ps_what_min_max(t_node *node, char *min_or_max);
void		ps_where_min_a(t_stack *stack, t_loc *loc);
void		ps_where_max_a(t_stack *stack, t_loc *loc);

#endif