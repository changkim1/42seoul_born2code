/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:52:59 by changkim          #+#    #+#             */
/*   Updated: 2022/06/30 13:10:23 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_open_file(char *filename, int check)
{
	if (check == IN)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, px_ft_strchr_i(filename, 0));
			write(STDERR, ": No such file of directory\n", 28);
			return (-1);
		}
		else
			return (open(filename, O_RDONLY));
	}
	else
	{
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	}
}

int main(int argc, char * const *argv, char **envp)
{
	int	in_fd;
	int	out_fd;
	
	if (argc == 5)
	{
		in_fd = px_open_file(argv[1], IN);
		out_fd = px_open_file(argv[4], OUT);
		dup2(in_fd, STDIN);
		dup2(out_fd, STDOUT);
		
	}
	else
		write(STDERR, "There must be 4 Arguments", 26);
}