#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
//#define _CRT_OBSOLETE_NO_WARNINGS

int main() {
	char* line;
	int	fd;
    //int i = 1;
    
    if ((!(fd = open("/mnt/c/Users/zzank/Desktop/coding/get_next_line/ch/files/41_with_nl", O_RDONLY))))	// 1
    {
    	printf("\nError in open");
        return (0);
    }
    while ((line = get_next_line(fd)))// 2
    {
    	//printf("Gnl %d line : %s\n", i++, line);
		!strcmp(line, "0123456789012345678901234567890123456789\n") ? printf("OK\n"):printf("NO\n");
        free(line);		// 6
    }
    free(line);					// 4
	close(fd);				// 5
    return (0);
}