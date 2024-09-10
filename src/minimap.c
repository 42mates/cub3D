/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/10 13:20:51 by mbecker          ###   ########.fr       */
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

static int	create_mini_map(t_data *data)
{
	int				i;
	int				j;
	int				color;
	unsigned int	*dst;

	j = 0;
	dst = (unsigned int *)data->img.d_a;
	while (j < data->map_h)
	{
		i = 0;
		while (i < data->map_w)
		{
			color = get_mini_color(data, i, j);
			if (color)
				*dst++ = color;
			// SEGFAULT somwhere here, idk why
			i++;
		}
		j++;
	}
	return (0);
}

void	draw_minimap(t_data *data)
{
	static int	first = 0;

	if (!first)
	{
		create_mini_map(data);
		first = 1;
	}
	//else
	//	update_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img_ptr, 0, 0);
}
