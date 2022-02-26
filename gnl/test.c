#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd = open("/mnt/c/Users/loves/Desktop/coding/gnl/test.txt", O_RDONLY);
	char buf[3];
	int n = read(fd, buf, 3);
	printf("%s\n", buf);
	while (n = read(fd, buf, 3) > 0)
	{
		printf("%s\n", buf);
	}
}
