#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool team[20] = {};
int	score[20][20] = {};
int n, result = 2147483647;

void	teamset(int idx, int cnt)
{
	int start_idx[20];
	int link_idx[20];
	int start_score = 0;
	int link_score = 0;

	if (cnt == (n/2))
	{
		int i = 0;
		int j = 0;
		while (i < n)
		{
			if (team[i] == true)
			{
				start_idx[j] = i;
				j++;
			}
			else
			{
				link_idx[j] = i;
				j++;
			}
			i++;
		}
		i = 0;
		while (i < (n/2))
		{
			int j = 0;
			while (j < (n/2))
			{
				start_score += score[start_idx[i]][start_idx[j]];
				link_score += score[link_idx[i]][link_idx[j]];
				j++;
			}
			if (abs(start_score - link_score) < result)
				result = abs(start_score - link_score);
			return ;
		}
	}
	int i = idx;
	while (i < n)
	{
		if (team[i])
			continue ;
		else
		{
			team[i] = true;
			teamset(i, cnt + 1);
			team[i] = false;
		}
		i++;
	}
}

int main(void)
{
	scanf("%d", &n);
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			scanf("%d", &score[i][j]);
			j++;
		}
		i++;
	}
	teamset(0, 0);
	return (result);
}