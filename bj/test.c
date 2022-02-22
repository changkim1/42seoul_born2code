#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_length(int	size, char	**strs, char	*sep)
{
	int	i;
	int	len;
	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len = len + (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		len;
	len = 0;
	if (size == 0)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	len = ft_length(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if(i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	str[len] = '\0';
	return (str);
}

int main(void)
{
	printf("----ex03----\n");
	char *strs[10];
	strs[0] = "Hello";
	strs[1] = "My";
	strs[2] = "name";
	strs[3] = "is";
	strs[4] = "sryou";
	strs[5] = "Nice";
	strs[6] = "to";
	strs[7] = "see";
	strs[8] = "you";
	strs[9] = "!!!";
	char *sep1 = " ";
	char *sep2 = "\n";
	char *sep3 = "---!!---";
	char *sep4 = "";
	char *str;
	str = ft_strjoin(5, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep2);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(2, strs, sep3);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(1, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(0, strs, sep1);
	printf("%s\n", str);
	free(str);
	str = ft_strjoin(10, strs, sep4);
	printf("%s\n", str);
	free(str);

	return (0);
}
