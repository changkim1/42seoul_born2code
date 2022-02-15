#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_it_palindrome(char *str, int len)
{
	char *ab;
	int i;

	i = 0;
	while (i <= len - i - 1)
	{
		if (str[i] != str[len - i - 1])
			return (0);
		i++;
	}
	ab = (char *)malloc(sizeof(char) * ((len / 2) + 1));
	i = 0;
	while (i < (len / 2))
	{		
		ab[i] = str[i];
		i++;	
	}
	ab[i] = 0;
	if (len == 1)
		return (1);
	else
		return (is_it_palindrome(ab, (len / 2)));
}

int main(void)
{
	char *str;
	char *ab;
	char *dwi;
	str = (char *)calloc(sizeof(char), 2000001);

	int i, plag, len;
	i = 0;
	plag = 0;
	scanf("%s", str);
	len = strlen(str);
	if (is_it_palindrome(str, len))
		plag = 1;
	if (plag == 0)
		printf("IPSELENTI");
	if (plag == 1)
		printf("AKARAKA");
	return (0);
}