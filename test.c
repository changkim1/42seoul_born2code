/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:31:00 by changkim          #+#    #+#             */
/*   Updated: 2022/06/30 21:47:54 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
	pid_t pid;
	pid = fork();
	int fd[2];
	pipe(fd);
	char str[13];
	printf("pid : %d %s\n", getpid(), str);
	// if(pipe(fd) < 0)
	// {
	// 	printf("pid : %d\n", getpid());
    //     printf("pipe error\n");
    //     exit(1);
    // }
    //  if((pid=fork())<0)
	//  {
	// 	printf("pid : %d\n", getpid());
    //     printf("fork error\n");
    //     exit(1);
    // }
	if (pid == 0)
	{
		close(fd[0]);
		strcpy(str, "par write\n");
		write(fd[1], str, strlen(str));
		printf("pid : %d %s\n", getpid(), str);
		
	}
	else
	{
		close(fd[1]);
		read(fd[0], str, 13);
		printf("pid : %d %s\n", getpid(), str);
	}
	exit(0);
}