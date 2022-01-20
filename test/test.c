#include <stdio.h>


int main(void)
{
	int	i;

	i = 0;
	printf("Text RPG 의 세계에 오신 것을 환영합니다.\n원하는 직업의 번호를 선택하여주세요. (숫자로만 적어주세요.)\n1. 전사  2. 마법사  3. 궁수\n");
	scanf("%d", &i);
	while (1)
	{
		if (i == 1)
		{
			printf("당신의 직업은 전사입니다.\n");
			break ;
		}
		else if(i == 2)
		{
			printf("당신의 직업은 마법사입니다.\n");
			break ;
		}
		else if (i == 3)
		{
			printf("당신의 직업은 궁수입니다.\n");
			break ;
		}
		else
		{
			while (1)
			{
				printf("다시 입력하여주세요.\n");
				scanf("%d", &i);
				if (i == 1 || i == 2 || i == 3)
					break ;
			}
			
		}
	}

	return 0;
}