#include "libft.h"
#include <string.h>

int main(void)
{
	int i;
	char **str;

	i = 0;
	str = ft_split("a123a456a789a0", 'a');
	while (str[i])
	{
		printf("%s ", str[i]);
		i++;
	}
}