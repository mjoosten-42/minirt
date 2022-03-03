#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

static t_mlx_image *g_img;

void	_clearr(t_mlx_image *img)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_putpixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
}

int32_t	main(void)
{
	t_mlx	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1);
	if (!mlx)
		exit(EXIT_FAILURE);
    g_img = mlx_new_image(mlx, 128, 128);
    mlx_image_to_window(mlx, g_img, 0, 0);
    mlx_putpixel(g_img, 64, 64, 0xFFFFFFFF);
	_clearr(g_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}