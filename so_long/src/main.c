#include "../includes/so_long.h"

int main(void)
{
	void	*mlx_ptr = mlx_init();
	void	*win_ptr = mlx_new_window(mlx_ptr, 900, 900, "test");
	mlx_clear_window(mlx_ptr, win_ptr);

}