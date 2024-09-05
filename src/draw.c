/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:07:19 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/05 11:56:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

// get access to the pixels and chang them to the color of the ceiling and floor
static void draw_c_and_f(t_data *data)
{
	unsigned int	*dst_pixel;
	unsigned int	i;
	
	dst_pixel = (unsigned int *)data->d_a;	// ptr to the first pixel color
	i = SIZE_X * SIZE_Y / 2 + 1;			// middle of the image
	//while (--i > 0)
	//	*dst_pixel++ = data->txtr.c;		// set the color and go to the next pixel
	//i = SIZE_X * SIZE_Y / 2 + 1;			// middle of the image
	//while (--i > 0)
	//	*dst_pixel++ = data->txtr.f;		// set the color and go to the next pixel
}

void	draw(t_data *data)
{
	data->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	data->d_a = mlx_get_data_addr(data->img, &data->bpp, &data->s_l, &data->en);
	draw_c_and_f(data);
	ray_casting(data);											// to draw the walls
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0); // to show the image in the window
	// put_minimap_to_window(data);
	mlx_destroy_image(data->mlx, data->img);						// no need it more

	(void)data;	// cc "unused variable" silencer
}

void draw_line(int x, float distance, t_data *data)
{
	unsigned int	height;
	
	height = (float) SIZE_X / distance;

	(void)x;	// cc "unused variable" silencer
	(void)data;	// cc "unused variable" silencer
}
