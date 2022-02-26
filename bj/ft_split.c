/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:34:48 by seokkim           #+#    #+#             */
/*   Updated: 2022/02/22 22:36:38 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include <stdio.h>

int	set_is_one(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_result_num(char *str, char *charset)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
        if (set_is_one(str[i], charset) == 0 && set_is_one(str[i + 1], charset) == 1)
		   	check++;
        i++;
    }
	return (check);
}

char	*make_one_line(int start, int finish, char *str)
{
	int		len;
	char	*result_one_line;
	int		i;

	i = 0;
	len = finish - start + 1;
	result_one_line = (char *)malloc(sizeof(char) * (len + 1));
    if (!result_one_line)
        return (NULL);
	while (i < len)
	{
		result_one_line[i] = str[start + i];
		i++;
	}
	result_one_line[i] = 0;
	return (result_one_line);
}

char	**check_str(char *str, char *charset, char **result)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && set_is_one(str[i], charset))
			i++;
		j = 0;
		while (str[i + j] && (set_is_one(str[i + j], charset) == 0))
			j++;
		result[k] = make_one_line(i, i + j - 1, str);
		k++;
		i = i + j;
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**result;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (check_result_num(str, charset) + 1));
    if(!result)
        return (NULL);
	result = check_str(str, charset, result);
	result[check_result_num(str, charset)] = 0;
	return (result);
}

#include <stdio.h>
int main(void)
{
		printf("----ex05----\n");
		char **str_arr;
		int i;
		str_arr = ft_split("Hello World Cat\tDog\nPizza School", " \n");
		for(i=0;str_arr[i] != 0; i++)
			printf("arr[%d] = %s\n", i, str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);
		printf("\n\n");
		str_arr = ft_split("Hello World Cat\tDog\nPizza School", " World");
		for(i=0;str_arr[i] != 0; i++)
			printf("arr[%d] = %s\n", i, str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);

}