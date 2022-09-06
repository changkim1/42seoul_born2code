#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
//#define _CRT_OBSOLETE_NO_WARNINGS

int main() {
	int	fd[4];

	fd[0] = open("files/43_with_nl", O_RDONLY);
	fd[1] = open("files/42_with_nl", O_RDONLY);
	fd[2] = open("files/41_with_nl", O_RDONLY);
	fd[3] = open("files/big_line_with_nl", O_RDONLY);
	
	printf("fd[0] = %s\n", get_next_line(fd[0]));	
	printf("fd[1] = %s\n", get_next_line(fd[1]));	
	printf("fd[2] = %s\n", get_next_line(fd[2]));	
	printf("fd[3] = %s\n", get_next_line(fd[3]));	
	printf("fd[0] = %s\n", get_next_line(fd[0]));	
	printf("fd[1] = %s\n", get_next_line(fd[1]));	
	printf("fd[2] = %s\n", get_next_line(fd[2]));	
	printf("fd[3] = %s\n", get_next_line(fd[3]));	
	printf("fd[0] = %s\n", get_next_line(fd[0]));	
	printf("fd[1] = %s\n", get_next_line(fd[1]));	
	printf("fd[2] = %s\n", get_next_line(fd[2]));	
	printf("fd[3] = %s\n", get_next_line(fd[3]));	
	printf("fd[0] = %s\n", get_next_line(fd[0]));	
	printf("fd[1] = %s\n", get_next_line(fd[1]));	
	printf("fd[2] = %s\n", get_next_line(fd[2]));	
	printf("fd[3] = %s\n", get_next_line(fd[3]));	
	
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);

	
    return (0);
}