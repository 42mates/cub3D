/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/10 16:23:09 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_mini_color(t_data *data, int i, int j)
{
	int	x;
	int	y;

	if ((size_t)i >= ft_strlen(data->map[j]))
		return (0);
	x = (int)(data->pos_x);
	y = (int)(data->pos_y);
	if (i == x && j == y)
		return (MINIMAP_PLAYER);
	if (data->map[j][i] == '1')
		return (MINIMAP_WALL);
	if (ft_is(data->map[j][i], "0NSWE"))
		return (MINIMAP_GROUND);
	return (0);
}

//static int	create_mini_map(t_data *data)
//{
//	int				i;
//	int				j;
//	int				color;
//	unsigned int	*dst;

//	j = 0;
//	dst = (unsigned int *)data->img.d_a;
//	while (j < data->map_h)
//	{
//		i = 0;
//		while (i < data->map_w)
//		{
//			color = get_mini_color(data, i, j);
//			if (color)
//				*dst = color;
//			dst++;
//			i++;
//		}
//		dst = (unsigned int *)data->img.d_a + SIZE_X * j;
//		j++;
//	}
//	return (0);
//}

//void	draw_minimap(t_data *data)
//{
//	static int	first = 0;

//	if (!first)
//	{
//		create_mini_map(data);
//		first = 1;
//	}
//	//else
//	//	update_minimap(data);
//	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img_ptr, MINIMAP_SCALE, MINIMAP_SCALE);
//}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;
	int i;
	int j;

	dst = (unsigned int *)data->img.d_a + MINIMAP_SCALE * (x + 1) + MINIMAP_SCALE * SIZE_X * (y + 1);

	i = -1;
	while (++i < MINIMAP_SCALE)
	{
		j = -1;
		while (++j < MINIMAP_SCALE)
			dst[j + SIZE_X * i] = color;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < data->map_w)
	{
		j = -1;
		while (++j < data->map_h)
		{
			color = get_mini_color(data, i, j);
			if (color)
				put_pixel_to_img(data, i, j, color);
		}
	}
}
