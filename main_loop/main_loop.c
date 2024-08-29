/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:21:17 by akurochk          #+#    #+#             */
/*   Updated: 2024/08/29 14:36:57 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main_loop(t_data *data)
{
	get_position(data);			// get the player's position at the start of the game (better in data initialization, after valid map)
	data->mlx = mlx_init();		// initialize the mlx pointer
	//get_textures(data);			// get the textures from the files
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cub3d");	// create a new window
	//draw(data);				// draw the first frame
	mlx_hook(data->win, ON_KEYDOWN, KeyPressMask, handle_key, data);	// change position and redraw (or ESC)
	mlx_hook(data->win, ON_DESTROY, NoEventMask, handle_destroy, data);	// destroy, free and exit
	mlx_loop(data->mlx);
	return (0);
}