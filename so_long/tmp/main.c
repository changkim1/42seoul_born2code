/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:52:49 by changkim          #+#    #+#             */
/*   Updated: 2022/06/23 00:38:08 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test(int fd, char *str)
{
	while (str != NULL)
	{
		str = get_next_line_no_new_line(fd);
		printf("%s\n", str);
	}
}

int main(void)
{
	char *str, *str1;
	int fd = open("test.txt", O_RDONLY);
	test(fd, str);
	printf("End\n");
	close(fd);
	fd = open("test.txt", O_RDONLY);
	test(fd, str1);
}