/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/11 13:05:41 by mbecker          ###   ########.fr       */
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

void	print_controls(void)
{
	write(1, "WASD - move\n", 12);
	write(1, "Arrows - rotate\n", 17);
	write(1, "M - toggle minimap\n", 20);
	write(1, "+- - change minimap scale\n", 27);
	write(1, "ESC - exit\n", 11);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data))
		return (free_data(&data), 1);
	print_controls();
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
