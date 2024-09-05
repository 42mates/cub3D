/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/05 15:53:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int	display_wdw(t_data *data, char *title, int width, int height)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_data(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, width, height, title);
	if (!data->win)
	{
		free_data(data);
		free(data->mlx);
		exit(1);
	}
	return (0);
}

void	init_data(t_data *data)
{
	printf("textures[0]: %s\n", data->textures[0]);
	printf("textures[1]: %s\n", data->textures[1]);
	printf("textures[2]: %s\n", data->textures[2]);
	printf("textures[3]: %s\n", data->textures[3]);
	printf("colors[0]: %d\n", data->colors[0]);
	printf("colors[1]: %d\n", data->colors[1]);
	printtab(data->map, 3);
	printf("map_h: %d\n", data->map_h);
	printf("map_w: %d\n", data->map_w);
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_v = 0.0;
	data->img = NULL;
	data->d_a = NULL;
	data->bpp = 0;
	data->s_l = 0;
	data->en = 0;
	data->win = NULL;
	data->mlx = NULL;
	//printf("pos_x: %f\n", data->pos_x);
	//printf("pos_y: %f\n", data->pos_y);
	//printf("dir_v: %f\n", data->dir_v);
	//printf("img: %p\n", data->img);
	//printf("d_a: %p\n", data->d_a);
	//printf("bpp: %d\n", data->bpp);
	//printf("s_l: %d\n", data->s_l);
	//printf("en: %d\n", data->en);
	//printf("win: %p\n", data->win);
	//printf("mlx: %p\n", data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data))
		return (free_data(&data), 1);
	
	init_data(&data);
		//init t_data content
		//open textures

	get_position(&data);

	display_wdw(&data, "cub3D", SIZE_X, SIZE_Y);
	
	//draw(&data);	// draw the first frame
	mlx_hook(data.win, ON_KEYDOWN, KeyPressMask, handle_key, &data);
	mlx_hook(data.win, ON_DESTROY, NoEventMask, handle_destroy, &data);
	mlx_loop(data.mlx);

	return (0);
}
