#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person	{
	int age;
	char name[101];
}persons;

int	compare(const void *s1, const void *s2)
{
	if (((persons *)s1)->age > ((persons *)s2)->age)
		return (1);
	if (((persons *)s1)->age < ((persons *)s2)->age)
		return (-1);
	return (0);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	persons ps[n];
	int i = 0;
	while (i < n)
	{
		scanf("%d", &ps[i].age);
		scanf("%s", ps[i].name);
		i++;
	}
	i = 0;
	int j = 0;
	qsort((persons *)ps, n, sizeof(persons), compare);
	i = 0;
	while (i < n)
	{
		printf("%d ", ps[i].age);
		printf("%s\n", ps[i].name);
		i++;
	}
}