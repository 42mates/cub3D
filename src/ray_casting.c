/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:15:04 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/11 11:47:51 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

static void	next_vertical_intersection(t_ray *r, t_data *data)
{
	if (r->x_sign == 0)
		r->d_h = INFINITY;
	else
	{
		r->y_v = data->p_y + r->dy / r->dx * (r->x_v - data->p_x);
		r->d_v = \
			sqrt(pow(data->p_x - r->x_v, 2.0) + pow(data->p_y - r->y_v, 2.0));
		r->s_ver = r->y_v - (int) r->y_v;
		if (r->x_sign > 0)
			r->s_ver = 1 - r->s_ver;
	}
}

static void	next_horizontal_intersection(t_ray *r, t_data *data)
{
	if (r->y_sign == 0)
		r->d_v = INFINITY;
	else
	{
		r->x_h = data->p_x + r->dx / r->dy * (r->y_h - data->p_y);
		r->d_h = \
			sqrt(pow(data->p_x - r->x_h, 2.0) + pow(data->p_y - r->y_h, 2.0));
		r->s_hor = r->x_h - (int) r->x_h;
		if (r->y_sign < 0)
			r->s_hor = 1 - r->s_hor;
	}
}

static void	save_txt(t_data *data, int id_txt, float w_txt)
{
	data->id_txt = id_txt;
	data->w_txt = w_txt;
}

static float	ray_scan(float a, t_data *data)
{
	t_ray	r;

	init_ray(&r, a, data);
	while (1)
	{
		next_vertical_intersection(&r, data);
		next_horizontal_intersection(&r, data);
		if (r.d_v < r.d_h)
		{
			if (data->map[(int) r.y_v][(int) r.x_v + (r.x_sign - 1) / 2] == '1')
				return (save_txt(data, r.x_sign + 1, 1 - r.s_ver), r.d_v);
			else
				r.x_v += r.x_sign;
		}
		else
		{
			if (data->map[(int) r.y_h + (r.y_sign - 1) / 2][(int) r.x_h] == '1')
				return (save_txt(data, r.y_sign + 2, 1 - r.s_hor), r.d_h);
			else
				r.y_h += r.y_sign;
		}
	}
}

void	ray_casting(t_data *data)
{
	int		n_line;
	float	l_dir;
	float	step;
	float	distance;

	n_line = -1;
	l_dir = data->dir_v - FOV / 2;
	step = FOV / (SIZE_X - 1);
	while (++n_line < SIZE_X)
	{
		distance = ray_scan(l_dir, data) * cos(data->dir_v - l_dir);
		draw_line(SIZE_X - n_line - 1, distance, data);
		l_dir += step;
	}
}
