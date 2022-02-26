/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:45 by user              #+#    #+#             */
/*   Updated: 2022/02/15 17:02:38 by changkim         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */

#include "get_next_line.h"

int	idx_is_new_line(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*return_result(char *backup_fd, int nl_idx)
{
	char	*tmp;
	char	*result;
	int	    after_dup; // dup 한 후 그 뒤 확인하기 위한 인덱스

	after_dup = ft_strlen(&backup_fd[nl_idx + 1]);
	backup_fd[nl_idx] = 0;
	result = ft_strdup(backup_fd);
	if (after_dup == 0)
	{
		free(backup_fd);
		backup_fd = 0;
		return (result);
	}
	tmp = ft_strdup(&backup_fd[nl_idx + 1]);
	free(backup_fd);
	backup_fd = ft_strdup(tmp);
	return (result);
}

char	*return_all(char *backup_fd, int read_size)
{
	char	*result;

	if (read_size < 0)//백업이 free 됐을 때
		return (NULL);
	result = ft_strdup(backup_fd); // 백업이 남아있는 경우, 저장시켜줌
	backup_fd = 0; // 끝났으니까 기억하고 있으면 안됨
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX]; // 받아온 걸 담아두고 어디까지 잘랐는지 기억할 문자열
	char		*buf; // read한 거 받아올 문자열
	char		*result;
	int	        read_size;
	int	        nl_idx;

	nl_idx = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || (BUFFER_SIZE) <= 0)
		return (NULL);
	read_size = read(fd, (char *)buf, BUFFER_SIZE);
	if (read_size == 0)
		return (0);
	while (read_size > 0)
	{
		buf[read_size] = 0; // 받아온 문자열 마지막 널값 채움
		backup[fd] = ft_strjoin(backup[fd], buf); // 백업 뒤에 읽어온 문자열 붙여놓기
		nl_idx = idx_is_new_line(backup[fd]); // 개행문자 만나면 그 개행문자 인덱스 받아옴, 없으면 -1 반환
		if (nl_idx != -1) // 개행 문자가 있으면
		{
			result = return_result(backup[fd], nl_idx);
			return (result); // 자른 결과 리턴, backup[fd] 에 남은거 저장
		}
		read_size = read(fd, (char *)buf, BUFFER_SIZE);
	}
	result = return_all(backup[fd], read_size);
	return (result); // 개행 문자가 없는 경우 EOF까지 남은거 반환
}