/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:15:04 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/09 15:56:01 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

int		get_sign(float x)
{
	if (x < 0.0f)
		return (-1);
	if (x == 0)
		return (0);
	return (1);
}

void	init_ray(t_ray *ray, float a, t_data *data)
{
	ray->dx = cos(a);
	ray->dy = -sin(a);

	ray->x_sign = get_sign(ray->dx);
	ray->y_sign = get_sign(ray->dy);

	ray->x_ver = (int) data->pos_x;
	ray->y_hor = (int) data->pos_y;

	if (ray->x_sign > 0)
		ray->x_ver += 1.0f;
	if (ray->y_sign > 0)
		ray->y_hor += 1.0f;
}

// to get the distance to the walls we need angle and data
float	ray_scan(float a, t_data *data) // a - angle of scan direction in radian
{
	int		i;
	int 	j;
	t_ray	ray;	// to store the ray data
	
	init_ray(&ray, a, data);	// to initialize the ray data
	
	while (1)	// breakpoint - a wall in a ray direction
	{
		// next vertical intesection
		if (ray.x_sign == 0)
		{
			ray.d_hor = INFINITY;
		}
		else
		{
			ray.y_ver = data->pos_y + ray.dy / ray.dx * (ray.x_ver - data->pos_x);
			ray.d_ver = sqrt(pow(data->pos_x - ray.x_ver, 2.0) + pow(data->pos_y - ray.y_ver, 2.0));
			ray.s_ver = ray.y_ver - (int) ray.y_ver;
			if (ray.x_sign > 0)
				ray.s_ver = 1 - ray.s_ver;
		}

		// next horizontal intersection
		if (ray.y_sign == 0)
		{
			ray.d_ver = INFINITY;
		}
		else
		{
			ray.x_hor = data->pos_x + ray.dx / ray.dy * (ray.y_hor - data->pos_y);
			ray.d_hor = sqrt(pow(data->pos_x - ray.x_hor, 2.0) + pow(data->pos_y - ray.y_hor, 2.0));
			ray.s_hor = ray.x_hor - (int) ray.x_hor;
			if (ray.y_sign < 0)
				ray.s_hor = 1 - ray.s_hor;
		}

		//----------------- to check the shortest distance -----------------

		if (ray.d_ver < ray.d_hor) // vertical grid collision
		{
			i = (int) ray.y_ver;
			j = (int) ray.x_ver + (ray.x_sign - 1) / 2;
			if (data->map[i][j] == '1') // is wall collision
			{
				// also we have to collect info about texture #NEWS
				data->id_txt = ray.x_sign + 1; // check if it will be 0 or 2 here
				data->w_txt = ray.s_ver;
				return (ray.d_ver);
			}
			else
			{
				ray.x_ver += ray.x_sign; // next vertical step
			}
		}
		else						// horizontal grid collision
		{
			i = (int) ray.y_hor + (ray.y_sign - 1) / 2;
			j = (int) ray.x_hor;
			if (data->map[i][j] == '1') // is wall collision
			{
				// also we have to collect info about texture #NEWS
				data->id_txt = ray.y_sign + 2; // it will be 1 or 3 here
				data->w_txt = ray.s_hor;
				return (ray.d_hor);
			}
			else
			{
				ray.y_hor += ray.y_sign; // next horizontal step
			}
		}
	}
}

// to draw the walls
void	ray_casting(t_data *data)
{
	int		n_line;	// number of the vertical line in the window
	float	l_dir;	// direction to the line in radian
	float	step;	// next line direction in a 'step' from current line
	
	n_line = -1;	// to start from the left line in the window
	l_dir = data->dir_v - FOV / 2;	// to start angle from the left line in the window
	step = FOV / (SIZE_X - 1);	// to get the step of the angle between the lines

	while (++n_line < SIZE_X) // to draw lines in the window
	{
		draw_line(SIZE_X - n_line, ray_scan(l_dir, data) * cos(data->dir_v - l_dir), data);
		l_dir += step;	// change direction to the next line
	}
}
