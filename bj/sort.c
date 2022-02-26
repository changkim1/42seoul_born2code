#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[11];
	int i;
	int len;

	i = 0;
	int count = 0;
	scanf("%s", str);
	len = strlen(str);
	char tmp = '0';
	while (count < len - 1)
	{
		i = 0;
		while (i < len - 1)
		{	
			if (str[i] < str[i + 1])
			{	
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	printf("%s", str);
}