/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:40:33 by changkim          #+#    #+#             */
/*   Updated: 2022/06/23 19:47:32 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_read(char *backup, int fd)
{
	char	*str;
	int		check;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	check = 1;
	while (!ft_strchr_gnl(backup, '\n') && check != 0)
	{
		check = read(fd, str, BUFFER_SIZE);
		if (check == -1)
		{
			free(str);
			return (NULL);
		}
		str[check] = 0;
		backup = ft_strjoin_gnl(backup, str);
	}
	free(str);
	return (backup);
}

char	*ft_return_oneline(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_backup(char *backup)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	tmp = (char *)malloc(1 * (ft_strlen_gnl(backup) - i));
	if (!tmp)
		return (NULL);
	i++;
	while (backup[i])
		tmp[j++] = backup[i++];
	tmp[j] = 0;
	free(backup);
	return (tmp);
}

char	*get_next_line_no_new_line(int fd)
{
	static char	*backup;
	char		*realline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read(backup, fd);
	if (!backup)
		return (NULL);
	realline = ft_return_oneline(backup);
	backup = ft_backup(backup);
	return (realline);
}
