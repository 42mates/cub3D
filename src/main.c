/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/09 17:19:24 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int	display_wdw(t_data *data, char *title, int width, int height)
{
	data->win = mlx_new_window(data->mlx, width, height, title);
	if (!data->win)
	{
		free_data(data);
		free(data->mlx);
		exit(1);
	}
	return (0);
}

int	init_data(t_data *data)
{
	int i;

	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_v = 0.0;
	data->win = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_data(data), 1);

	i = -1;
	while (++i < 4)
	{
		data->img_txt[i].img_ptr = mlx_xpm_file_to_image(data->mlx, data->textures[i], &data->img_txt[i].size_x, &data->img_txt[i].size_y);
		printf("data->textures[i] = %s\n", data->textures[i]);
		if (!data->img_txt[i].img_ptr)
			return (error("init_data()", "couldn't create image"));
		data->img_txt[i].d_a = mlx_get_data_addr(data->img_txt[i].img_ptr, &data->img_txt[i].bpp, &data->img_txt[i].s_l, &data->img_txt[i].en);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data))
		return (free_data(&data), 1);
	
	if (init_data(&data))
		return (free_data(&data), 1);

	get_position(&data);

	display_wdw(&data, "cub3D", SIZE_X, SIZE_Y);
	
	draw(&data);

	mlx_hook(data.win, ON_KEYDOWN, KeyPressMask, handle_key, &data);
	mlx_hook(data.win, ON_DESTROY, NoEventMask, handle_destroy, &data);
	mlx_loop(data.mlx);

	return (0);
}
