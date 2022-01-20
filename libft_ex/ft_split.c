#include "libft.h"

static size_t	index_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**free_all(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*strdup_len(const char *s, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return(0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	**str;

	i = -1;
	j = 0;
	index = 0;
	if (!(str = (char **)malloc(sizeof(char *) * index_cnt(s, c))))
		return (0);
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j])
				j++;
			if (!(str[index] = strdup_len(&s[i], j)))
				return (free_all(str));
			i = i + j - 1;
			index++;
			j = 0;
		}
	}
	str[index] = 0;
	return (str);
}

int main(void)
{
	int i;
	char c;
	char **str;

	i = 0;
	c = 'd';
	str = ft_split("성d공d!!!!!!!!d!!!!!!!!!!돼!!!!!따!!!!!!!!!!d!", c);
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
}