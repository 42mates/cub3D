/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:07:19 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/10 13:13:00 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

// get access to the pixels and chang them to the color of the ceiling and floor
static void draw_c_and_f(t_data *data)
{
	unsigned int	*dst_pixel;
	unsigned int	i;
	
	dst_pixel = (unsigned int *)data->img.d_a;	// ptr to the first pixel color
	i = SIZE_X * SIZE_Y / 2 + 1;			// middle of the image
	while (--i > 0)
		*dst_pixel++ = data->colors[C];		// set the color and go to the next pixel
	i = SIZE_X * SIZE_Y / 2 + 1;			// middle of the image
	while (--i > 0)
		*dst_pixel++ = data->colors[F];		// set the color and go to the next pixel
}

void	draw(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	if (!data->img.img_ptr)
		error("draw()", "couldn't create image");
	data->img.d_a = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.s_l, &data->img.en);
	draw_c_and_f(data);
	ray_casting(data);											// to draw the walls
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0); // to show the image in the window
	draw_minimap(data);										// to draw the minimap
	mlx_destroy_image(data->mlx, data->img.img_ptr);						// no need it more
}

void draw_line(int x, float distance, t_data *data)
{
	int		*src;			// pointer to the first source image pixel
	int		*dst;			// pointer to the destination image pixel
	int		l_len;			// length of vertical line (part of wall)
	float	l_pos;			// position in the line, helps to get correct color
	float	step;			// step (vertical) to the next pixel in the source image 
	

	l_len = (float) SIZE_Y / distance; // length in scale in pixels;
	step = (float) data->img_txt[data->id_txt].size_y / l_len;
	l_pos = 0.0f;
	
	if (l_len > SIZE_Y) // if closer than '1' (we have grid size 1x1)
	{
		l_pos = 0.5f * (l_len - SIZE_Y) / l_len * data->img_txt[data->id_txt].size_y; // line will be copied from firs visiable pixel of texture
		l_len = SIZE_Y;
	}
	
	src = (int *) data->img_txt[data->id_txt].d_a; // pointer to the first pixel of the source image
	src += (int)((float)data->w_txt * data->img_txt[data->id_txt].size_x); // go to first visaiable pixel
	
	dst = (int *) data->img.d_a; // pointer to the first pixel of the destination image
	dst += x + (SIZE_Y - l_len) / 2 * SIZE_X; // go to the first pixel of the line

	while (l_len-- > 0) 
	{
		*dst = *(src + ((int)l_pos) * data->img_txt[data->id_txt].size_x); // set the pixel color
		dst += SIZE_X; // go to the next pixel (down)
		l_pos += step; // go to the next pixel in src image;
	}
}
