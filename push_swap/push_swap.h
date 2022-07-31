/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:32 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/15 16:37:33 by zzankor          ###   ########.fr       */
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
int	*ps_bubble_sort(int *array, int w_count);

/////////////// make_array.c ///////////////
int		*ps_make_array(int ac, char **av, int w_count, int *array);
int		ps_count_word(int ac, char **av);


/////////////// error.c ///////////////
void	ps_print_error(char *message);
int		ps_check_duplicate(int *array, int w_count);
void	ps_free_str(char **str);

#endif