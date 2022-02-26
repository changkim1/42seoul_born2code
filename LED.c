#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TIMER 0.5
#define COUNT 10
#define mymax 100000000

int delay = (TIMER * 1000000);

int main(void)
{
	char *SW;
	int push;
	int count = 0;
	printf("Switch 를 push 하려면 push를 입력하십시오.\n");
	SW = (char *)calloc(sizeof(char), mymax);
	scanf("%s", SW);
	while (strcmp(SW, "push"))
	{
		free(SW);
		SW = (char *)calloc(sizeof(char), mymax);
		printf("\n다시 입력하십시오.\n\n종료하려면 end 를 입력하십시오.\n\n");
		scanf("%s", SW);
		if (!strcmp(SW, "end"))
		{
			printf("\nLED 프로그램을 종료합니다.\n");
			free(SW);
			return (0);
		}
	}
	if (!strcmp(SW, "push"))
	{
		push = 1;
		fflush(stdout);
		usleep((delay * 2) / 3);
		printf("\nSWITCH PUSHED!!!!\n\n");
		fflush(stdout);
		usleep(delay);
		printf("LED 프로그램이 시작됩니다.\n");
		fflush(stdout);
		usleep(delay * 2);
		printf("3  ");
		fflush(stdout);
		usleep(delay * 2);
		printf("2  ");
		fflush(stdout);
		usleep(delay * 2);
		printf("1");
		fflush(stdout);
		usleep(delay * 2);
		printf("\n\n");
		while (count < COUNT && push == 1)
		{
			printf("ON\n\n");
			fflush(stdout);
			usleep(delay);
			printf("OFF\n\n");
			fflush(stdout);
			usleep(delay);
			count++;
		}
	}
	printf("ON\n\n");
	fflush(stdout);
	usleep(delay);
	printf("LED OFF\n\n");
	printf("LED 프로그램을 종료합니다.\n");
	free(SW);
	return (0);
}