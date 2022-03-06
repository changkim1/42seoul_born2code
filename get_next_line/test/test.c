#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char *str;
	str = (char *)malloc(4);
	int check = 1;
	int fd = open("test1.txt", O_RDONLY);
	while ((check = read(fd, str, 3)))
	{
		printf("check = %d\n", check);
		usleep(500000);
		str[check] = 0;
		printf("%s\n", str);
	}
}