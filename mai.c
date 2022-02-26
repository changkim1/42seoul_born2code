/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mai.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:41:30 by youjpark          #+#    #+#             */
/*   Updated: 2022/02/21 20:13:56 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	printf("----ex03----\n");
	char *strs[10];
	strs[0] = "Hello";
	strs[1] = "My";
	strs[2] = "name";
	strs[3] = "is";
	strs[4] = "sryou";
	strs[5] = "Nice";
	strs[6] = "to";
	strs[7] = "see";
	strs[8] = "you";
	strs[9] = "!!!";
	char *sep1 = " ";
	char *sep2 = "\n";
	char *sep3 = "---!!---";
	char *sep4 = "";
	char *str;
	str = ft_strjoin(5, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep2);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(2, strs, sep3);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(1, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(0, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep4);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep2);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep3);
	printf("%s\n", str);
	free(str);
}
