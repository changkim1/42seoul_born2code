#include "includes/so_long.h"

void	put_them(void *win, void *mlx, t_img *img)
{
	for(int i = 0; i<10; i++)
	{
		mlx_put_image_to_window(mlx, win, img->wall, i * 60, i * 60);
	}
	printf("%p\n", img->wall);
}

int main(void)
{
	int	wid;
	int	hei;
	t_img img;

	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "my_mlx");
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	printf("%p\n", img.wall);
	put_them(win, mlx, &img);
	mlx_loop(mlx);
	return (0);
}