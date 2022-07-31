#include <stdlib.h>
#include <stdio.h>

typedef struct s_numbers
{
	struct s_numbers	*prev;
	int					content;
	struct s_numbers	*next;
}			t_numbers;

typedef struct s_info
{
	int					*array;
	int					size_a;
	struct s_numbers	*top_a;
	struct s_numbers	*bottom_a;
	int					size_b;
	struct s_numbers	*top_b;
	struct s_numbers	*bottom_b;
}			t_info;

t_info	*ft_info_new(void)
{
	t_numbers	*stack_a;
	t_info		*new_mem;

	new_mem = NULL;
	new_mem = (t_info *)malloc(sizeof(t_info));
	stack_a = ft_stack_new();
	new_mem->array = NULL;
	new_mem->size_a = 0;
	new_mem->top_a = stack_a;
	new_mem->bottom_a = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

int	main(int ac, char *av[])
{
	int			array_size;
	int			*num_array;
	t_info		*info;

	if (ac < 2)
	{
		print_error(-1);
	}	
	array_size = 0;
	info = ft_info_new();
}