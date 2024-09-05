#include "minilibx-linux/mlx.h"

#include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key)
		handle_destroy(data);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 640, 480, "Hello world!");
	mlx_hook(data.win, 2, 1L<<0, handle_key, &data);
	mlx_hook(data.win, 17, 1L<<17, handle_destroy, &data);
	mlx_loop(data.mlx);
}