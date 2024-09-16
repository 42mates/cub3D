/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:14:47 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/16 12:48:38 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->img_txt[i].img_ptr = mlx_xpm_file_to_image(
				data->mlx, data->textures[i], &data->img_txt[i].size_x,
				&data->img_txt[i].size_y);
		if (!data->img_txt[i].img_ptr)
			return (error("init_img()", "couldn't create image"));
		data->img_txt[i].d_a = mlx_get_data_addr(data->img_txt[i].img_ptr,
				&data->img_txt[i].bpp, &data->img_txt[i].s_l,
				&data->img_txt[i].en);
	}
	return (0);
}

int	init_data(t_data *data)
{
	data->p_x = 0.0;
	data->p_y = 0.0;
	data->dir_v = 0.0;
	data->allow_minimap = 1;
	data->mini_scale = MINIMAP_SCALE;
	data->win = NULL;
	data->mlx = mlx_init();
	data->mouse_down = 0;
	data->mouse_x = 0;
	if (!data->mlx)
		return (free_data(data), 1);
	if (init_img(data))
		return (1);
	return (0);
}

static int	get_sign(float x)
{
	if (x < 0.0f)
		return (-1);
	if (x == 0)
		return (0);
	return (1);
}

void	init_ray(t_ray *r, float a, t_data *data)
{
	r->dx = cos(a);
	r->dy = -sin(a);
	r->x_sign = get_sign(r->dx);
	r->y_sign = get_sign(r->dy);
	r->x_v = (int) data->p_x;
	r->y_h = (int) data->p_y;
	if (r->x_sign > 0)
		r->x_v += 1.0f;
	if (r->y_sign > 0)
		r->y_h += 1.0f;
}
