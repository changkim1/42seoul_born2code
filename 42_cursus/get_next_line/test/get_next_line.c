#include "get_next_line.h"

char	*ft_read(char *backup, int fd)
{
	int		check;
	char	*str;
	
	check = 1;
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(backup, '\n') && check != 0)
	{
		check = read(fd, str, BUFFER_SIZE);
		if (check == -1)
		{
			free(str);
			return (NULL);
		}
		str[check] = 0;
		backup = ft_strjoin(backup, str);
	}
	free(str);
	return (backup);
}

char	*ft_return_oneline(char *backup)
{
	int	i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] !='\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_backup(char *backup)
{
	int	i;
	int j;
	char	*tmp;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	tmp = (char *)malloc(ft_strlen(backup) - i);
	if (!tmp)
		return (NULL);
	i++;
	while (backup[i + j])
	{
		tmp[j] = backup[i + j];
		j++;
	}
	tmp[j] = 0;
	free(backup);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*realline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	backup[fd] = ft_read(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	realline = ft_return_oneline(backup[fd]);
	backup[fd] = ft_backup(backup);
}