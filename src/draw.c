/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:07:19 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/11 16:19:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

// get access to the pixels and chang them to the color of the ceiling and floor
static void	draw_c_and_f(t_data *data)
{
	unsigned int	*dst_pixel;
	unsigned int	i;

	dst_pixel = (unsigned int *)data->img.d_a;
	i = SIZE_X * SIZE_Y / 2 + 1;
	while (--i > 0)
		*dst_pixel++ = data->colors[C];
	i = SIZE_X * SIZE_Y / 2 + 1;
	while (--i > 0)
		*dst_pixel++ = data->colors[F];
}

void	draw(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	if (!data->img.img_ptr)
		error("draw()", "couldn't create image");
	data->img.d_a = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.s_l, &data->img.en);
	draw_c_and_f(data);
	ray_casting(data);
	if (data->allow_minimap)
		draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img_ptr);
}

void	draw_line(int x, float distance, t_data *data)
{
	int		*src;
	int		*dst;
	int		l_len;
	float	l_pos;
	float	step;

	l_len = (2 / distance) * ((SIZE_Y / 2) / tan(FOV / 2));
	step = (float)data->img_txt[data->id_txt].size_y / l_len;
	l_pos = 0.0f;
	if (l_len > SIZE_Y)
	{
		l_pos = 0.5f * (l_len - SIZE_Y) / l_len
			* data->img_txt[data->id_txt].size_y;
		l_len = SIZE_Y;
	}
	src = (int *)data->img_txt[data->id_txt].d_a;
	src += (int)((float)data->w_txt * data->img_txt[data->id_txt].size_x);
	dst = (int *)data->img.d_a;
	dst += x + (SIZE_Y - l_len) / 2 * SIZE_X;
	while (l_len-- > 0)
	{
		*dst = *(src + ((int)l_pos) * data->img_txt[data->id_txt].size_x);
		dst += SIZE_X;
		l_pos += step;
	}
}
