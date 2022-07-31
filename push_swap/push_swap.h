/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:32 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/31 18:12:02 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}				t_stack;

typedef struct	s_pivot
{
	int	big;
	int	small;
}				t_pivot;

/////////////// utils.c ///////////////
long long	ps_atoi_ll(char *str);

/////////////// sort_array.c ///////////////
void		ps_bubble_sort(int *array, int array_size);

/////////////// error.c ///////////////
void		ps_print_error(char *message);
void		ps_free_str(char **str);

////////////////// make_array.c //////////////////
int			ps_check_array_size(char **av, int ac);
int			*ps_make_array(char **av, int ac, int *array);

////////////////// check_array.c //////////////////
void		ps_check_duplicate(int *array, int array_size);
int			ps_check_limit(char *word);

////////////////// make_stack.c //////////////////
t_node	*ps_make_new_node(void);
t_stack	*ps_get_stack(t_stack *stack_a);
void	ps_array_to_stack(int *array, int array_size, t_stack *stack_a);  


#endif