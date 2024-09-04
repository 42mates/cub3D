/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:21:17 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/04 17:40:42 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main_loop(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cub3d");

	draw(data);				// draw the first frame

	mlx_hook(data->win, ON_KEYDOWN, KeyPressMask, handle_key, data);	// change position and redraw (or ESC)
	mlx_hook(data->win, ON_DESTROY, NoEventMask, handle_destroy, data);	// destroy, free and exit
	mlx_loop(data->mlx);

	return (0);
}