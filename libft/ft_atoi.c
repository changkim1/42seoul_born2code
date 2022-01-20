int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	plma;

	i = -1;
	num = 0;
	plma = 1;
	while (str[++i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			continue ;
		if (str[i] == '-')
			plma *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num + (str[i] - 48);
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break ;
			num *= 10;
		}
	}
	return (plma * num);
}
