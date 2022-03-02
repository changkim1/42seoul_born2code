/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:58:34 by changkim          #+#    #+#             */
/*   Updated: 2022/03/02 16:41:54 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *read_one)
{
	char	*str;
	int		check;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	check = 1;
	while (!ft_strchr(read_one, '\n') && check != 0) // 받아놓은 것 중에 개행이 있거나 다 읽었을 경우 제외
	{
		check = read(fd, str, BUFFER_SIZE);
		if (check == -1) // read 실패 시 -1 리턴
		{
			free(str);
			return (NULL);
		}
		str[check] = '\0';
		read_one = ft_strjoin(read_one, str); // read_one (받아놓을 문자열), str (read하고 read_one 에 전달하기 위한 tmp)
	}
	free(str);
	return (read_one);
}

char	*ft_linemaker(char *read_one) // read 한 read_one를 파라미터로 받음
{
	int		i;
	char	*str;

	i = 0;
	if (!read_one[i]) // read_one가 비어있음.
		return (NULL);
	while (read_one[i] && read_one[i] != '\n') // 개행을 만나거나 read_one 가 끝날 때까지
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); // 개행을 넣어줄 수도 있기 때문에 i + 2
	if (!str)
		return (NULL);
	i = 0;
	while (read_one[i] && read_one[i] != '\n') // 개행을 만나거나 read_one가 끝날 때까지
	{
		str[i] = read_one[i]; // 복사해줌
		i++;
	}
	if (read_one[i] == '\n') // 개행을 만난거라면
	{
		str[i] = read_one[i]; // 개행 넣어줌
		i++;
	}
	str[i] = '\0'; // 마지막 널값 넣어줌
	return (str);
}

char	*ft_nextline(char *read_one)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (read_one[i] && read_one[i] != '\n') // 자른 곳까지 인덱스를 보내줌.
		i++;
	if (!read_one[i]) // 그 뒤에값이 더 이상 없다면 (끝까지 읽은 경우)
	{
		free(read_one);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(read_one) - i + 1)); // 자르고 담아놓을 문자열 (read_one 총 길이 - 이미 잘라서 보내 놓은 것들 + 1(널값))
	if (!str)
		return (NULL);
	i++; // 개행 다음부터 시작하기 위해
	while (read_one[i])
		str[j++] = read_one[i++]; // 복사해줌
	str[j] = '\0';
	free(read_one);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*realline;
	static char	*read_one;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_one = ft_read(fd, read_one); // 읽어와서 read_one 에 저장시켜둠
	if (!read_one)
		return (NULL); // read_one 에 제대로 못 받아왔을 경우 (read 리턴값이 -1 일 때)
	realline = ft_linemaker(read_one); // read_one를 개행 이나 널값 전까지 복사해준 문자열을 리턴
	read_one = ft_nextline(read_one); // 남은거 read_one에 저장시켜둔 채로 종료 static char 형이기 때문에 다음 번에 불러와도 이 상태의 read_one를 기억하고 있음.
	return (realline);
}
