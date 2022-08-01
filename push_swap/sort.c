/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:11:33 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 19:31:03 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ps double check 함수에서 oper_set 의 마지막 원소 하나가 남음. 이거 하나 마지막에 처리 해줘야함.
void	ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	**oper_set;
	
	oper_set = (char **)malloc(sizeof(char *) * 4);
	if (!oper_set)
		exit(1);
}