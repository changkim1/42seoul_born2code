/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:52:59 by changkim          #+#    #+#             */
/*   Updated: 2022/07/04 14:41:46 by zzankor          ###   ########.fr       */
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
			write(STDERR, filename, px_strchr_idx(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			exit(1);
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

void	px_redirection(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		ret;

	ret = pipe(fd);
	pid = fork();
	if (ret < 0)
		print_error_with_nl(1, "pipex: fork error");
	if (pid < 0)
		print_error_with_nl(1, "pipex: pipe error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		px_execve(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
}

void	px_execve(char *cmd, char **envp)
{
	char	*path;
	char	**split_cmd;
	
	split_cmd = ft_split(cmd, ' ');
	path = px_make_path(envp, split_cmd);
	execve(path, split_cmd, envp);
	free(split_cmd);
	write(STDERR, "pipex: command not found: ", 27);
	print_error_with_nl(127, cmd);
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
		px_redirection(argv[2], envp);
		px_execve(argv[3], envp);
	}
	else
		write(STDERR, "There must be 4 Arguments", 26);
	return (1);
}