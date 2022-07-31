/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:25 by zzankor           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/20 18:15:23 by changkim         ###   ########.fr       */
=======
/*   Updated: 2022/07/15 15:51:40 by zzankor          ###   ########.fr       */
>>>>>>> cd5f050cec0468b4b05b2b744d42c989d8c0f046
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
<<<<<<< HEAD
	// t_stack	*stack_a;
	int		*array;
	int		array_size;

	if (ac < 2)
		return (0);
	array_size = ps_check_array_size(av, ac);
	array = (int *)malloc(sizeof(int) * array_size);
	if (!array)
		exit(1);
	array = ps_make_array(av, ac, array);
	int i = 0;
	while (i < array_size)
	{
		fprintf(stderr, "%d\n", array[i]);
		i++;
	}
	// stack_a = (t_stack *)malloc(sizeof(t_stack));
=======
	int	*array;
	int	w_count;

	if (ac == 1)
		return (0);
	w_count = ps_count_word(ac, av);
	array = ps_make_array(ac, av, w_count, array);
	ps_check_duplicate(array, w_count);
	array = ps_bubble_sort(array, w_count);
	for (int i = 0; i < w_count; i++)
		printf("%d ", array[i]);
	printf("\n");
>>>>>>> cd5f050cec0468b4b05b2b744d42c989d8c0f046
}