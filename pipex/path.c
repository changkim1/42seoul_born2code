/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:49:30 by changkim          #+#    #+#             */
/*   Updated: 2022/07/04 21:34:15 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*px_find_path(char **envp)
{
	int	i;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		if (px_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == 0)
		return (NULL);
	tmp = px_substr(envp[i], 5, px_strchr_idx(envp[i], 0) - 5);
	return (tmp);
}

char	*px_change_to_slash(char *path)
{
	int		i;
	char	*tmp;
	
	i = 0;
	tmp = (char *)malloc(px_strchr_idx(path, 0) + 2);
	while (path[i])
	{
		if (path[i] == ':')
		{
			path[i] = '/';
			free(tmp);
			return (path);
		}
		i++;
	}
	tmp = px_strdup(path);
	tmp[i] = '/';
	tmp[i + 1] = '\0';
	free(path);
	return (tmp);
}

char	*px_make_path(char **envp, char **cmd)
{
	int		i;
	int		j;
	char	*path;
	char	*tmp;
	
	i = -1;
	j = 0;
	tmp = px_find_path(envp);
	while (tmp[++i])
	{
		if (tmp[i + 1] == ':' || tmp[i + 1] == 0)
		{
			path = px_substr(tmp, j, i - j + 2);
			path = px_change_to_slash(path);
			path = px_strjoin(path, cmd[0]);
			if (access(path, F_OK) == 0)
				return (path);
			if (tmp[i + 1] == 0)
				return (NULL);
			j = i + 2;
		}
	}
	free(tmp);
	return (NULL);
}
