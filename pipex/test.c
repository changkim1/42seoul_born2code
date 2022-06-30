#include "pipex.h"
#include <stdio.h>

int main(void)
{
	int fd = open("file4", O_RDONLY);
	printf("%d\n", fd);
}