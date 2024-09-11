/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/11 12:56:06 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_mini_color(t_data *data, int i, int j)
{
	int	x;
	int	y;

	if ((size_t)i >= ft_strlen(data->map[j]))
		return (0);
	x = (int)(data->p_x);
	y = (int)(data->p_y);
	if (i == x && j == y)
		return (MINIMAP_PLAYER);
	if (data->map[j][i] == '1')
		return (MINIMAP_WALL);
	if (ft_is(data->map[j][i], "0NSWE"))
		return (MINIMAP_GROUND);
	return (0);
}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;
	int				i;
	int				j;

	dst = (unsigned int *)data->img.d_a + data->mini_scale * (x + 1)
		+ data->mini_scale * SIZE_X * (y + 1);
	i = -1;
	while (++i < data->mini_scale)
	{
		j = -1;
		while (++j < data->mini_scale)
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
