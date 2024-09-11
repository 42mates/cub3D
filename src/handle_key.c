/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:27:45 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/11 12:57:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int	is_blocked(char dir, t_data *data, float offset)
{
	float	new_x;
	float	new_y;

	new_x = data->p_x;
	new_y = data->p_y;
	if (dir == 'x')
		new_x += offset;
	else if (dir == 'y')
		new_y -= offset;
	if (ft_is(data->map[(int)new_y][(int)new_x], " 1\n")
		|| !data->map[(int)new_y][(int)new_x])
		return (1);
	return (0);
}

static void	move(t_data *data, int dir)
{
	float	dx;
	float	dy;
	float	a;

	a = data->dir_v + dir * M_PI_2;
	dx = cos(a) * SPEED;
	dy = sin(a) * SPEED;
	if (!is_blocked('x', data, dx))
		data->p_x += dx;
	if (!is_blocked('y', data, dy))
		data->p_y -= dy;
}

static void	rotate(t_data *data, int dir)
{
	if (dir == 1 || dir == -1)
		data->dir_v += -dir * SPEED_R * M_PI;
}

int	handle_key(int key, t_data *data)
{
	if (key == KEY_ESC)
		handle_destroy(data);
	else if (key == KEY_W)
		move(data, 0);
	else if (key == KEY_A)
		move(data, 1);
	else if (key == KEY_S)
		move(data, 2);
	else if (key == KEY_D)
		move(data, 3);
	else if (key == KEY_LEFT)
		rotate(data, -1);
	else if (key == KEY_RIGHT)
		rotate(data, 1);
	else if (key == KEY_M)
		data->allow_minimap = !data->allow_minimap;
	else if (key == KEY_MIN && data->mini_scale > 2)
		data->mini_scale -= 1;
	else if (key == KEY_PLUS && data->mini_scale < 16)
		data->mini_scale += 1;
	else
		return (0);
	draw(data);
	return (0);
}
