/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:42:39 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/16 13:14:10 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int	handle_mouse_d(int button, int x, int y, t_data *data)
{
	(void) y;
	if (button == 1 && data->mouse_down == 0)
	{
		data->mouse_down = 1;
		data->mouse_x = x;
	}
	return (0);
}

int	handle_mouse_m(int x, int y, t_data *data)
{
	int		dx;
	float	step;

	(void) y;
	if (data->mouse_down)
	{
		dx = x - data->mouse_x;
		data->mouse_x += dx;
		step = FOV / (SIZE_X - 1);
		data->dir_v -= dx * step * 5;
		if (data->dir_v > 2 * M_PI)
			data->dir_v -= 2 * M_PI;
		if (data->dir_v < -2 * M_PI)
			data->dir_v += 2 * M_PI;
		draw(data);
	}
	return (0);
}

int	handle_mouse_u(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == 1 && data->mouse_down == 1)
		data->mouse_down = 0;
	return (0);
}
