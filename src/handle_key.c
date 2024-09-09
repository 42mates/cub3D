/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:27:45 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/09 16:18:01 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int	is_blocked(char dir, t_data *data, float offset)
{
	float	new_x;	
	float	new_y;	

	new_x = data->pos_x;
	new_y = data->pos_y;
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
	float	a;		// angle
	float	d;		// distance to the wall x or y direction

	a = data->dir_v + dir * M_PI_2;
	dx = cos(a) * SPEED;
	dy = sin(a) * SPEED;
	
	// // check wall collision
	// d = ray_scane(); // get the distance to the wall x-direction
	// if (d * d < dx * dx) // if we cant do the step, we dont do it
	// 	dx = 0.0f;
	// d = ray_scane(); // same for y-direction
	// if (d * d < dy * dy)
	// 	dy = 0.0f;
	// //also we should check distance in the direction of the view
	
	// then update player's position
	if (!is_blocked('x', data, dx))
		data->pos_x += dx;
	if (!is_blocked('y', data, dy))
		data->pos_y -= dy;

	(void)d;	// cc "unused variable" silencer
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
	else 					// nothing if another key. here we can add more reactions
		return (0);
	printf("pos_x = %f, pos_y = %f, dir_v = %f\n", data->pos_x, data->pos_y, data->dir_v);
	draw(data);				// draw the new frame in case of handled key
	return (0);
}