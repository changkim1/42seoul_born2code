/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_loc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:07:04 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 23:08:51 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_loc	ps_loc_cpy(t_loc *loc)
{
	t_loc	tmp;
	
	tmp.real_a = loc->real_a;
	tmp.real_b = loc->real_b;
	tmp.tmp_a = loc->tmp_a;
	tmp.tmp_b = loc->tmp_b;
	tmp.max_a = 0;
	tmp.max_b = 0;
	tmp.min_a = 0;
	tmp.min_b = 0;
	return (tmp);
}