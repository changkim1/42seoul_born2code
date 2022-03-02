#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define _CRT_OBSOLETE_NO_WARNINGS

int main() {
	char* line;
	int	fd;
    int i = 1;
    
    if ((!(fd = open("/mnt/c/Users/zzank/Desktop/coding/get_next_line/test1.txt", O_RDONLY))))	// 1
    {
    	printf("\nError in open");
        return (0);
    }
    while ((line = get_next_line(fd)))// 2
    {
    	printf("Gnl %d line : %s\n", i++, line);
        free(line);		// 6
		usleep(500000);
    }
    
    free(line);					// 4
	close(fd);				// 5
    return (0);
}