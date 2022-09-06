/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:55 by zzankor           #+#    #+#             */
/*   Updated: 2022/08/05 00:23:38 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	ps_free_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->a_top;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(stack);
}

void	ps_print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}
