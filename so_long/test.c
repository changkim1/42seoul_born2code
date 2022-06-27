#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *m_a(char *str)
{
	str = malloc(7);
	strcpy(str, "1234");
	return (str);
}

int main(void)
{
	char *str;
	str = m_a(str);
	system("leaks a.out");
	return (0);	
}