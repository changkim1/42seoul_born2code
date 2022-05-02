#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) // buf 를 읽어올 때마다 계속해서 하나씩 잘 들어가는지 체크
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

#include "get_next_line.h"

int main() { // mandatory 확인 메인
	char* line;
	int	fd;
    
    if ((!(fd = open("/mnt/c/Users/zzank/Desktop/coding/42seoul/get_next_line/hbae/test1.txt", O_RDONLY))))	// 1
    {
    	printf("\nError in open");
        return (0);
    }
    while ((line = get_next_line(fd)))		// 2
    {
    	printf("line : %s\n", line);	
        free(line);				// 6
		usleep(500000);
    }
    
    free(line);					// 4
	close(fd);				// 5
    return (0);
}

int fd[OPEN_MAX]; // 보너스 확인 메인

fd[0] = open("gnlTester/files/43~~", O_RDONLY);
fd[1] = open("gnlTester/files/43~~", O_RDONLY);
fd[2] = open("gnlTester/files/43~~", O_RDONLY);

close(fd[0]);
close(fd[1]);
close(fd[2]);
