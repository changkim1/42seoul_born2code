/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:05:02 by changkim          #+#    #+#             */
/*   Updated: 2022/08/18 00:16:27 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>



int	main(void)
{
	char	*oper;
	t_stack	*stack;

	oper = (char *)malloc(3);
	if (!oper)
		exit(1);
	stack = ps_get_stack(stack);
	
}