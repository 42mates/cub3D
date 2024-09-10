/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:14:47 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/10 12:58:53 by mbecker          ###   ########.fr       */
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
			&data->img_txt[i].bpp, &data->img_txt[i].s_l, &data->img_txt[i].en);
	}
	return (0);
}

int	init_data(t_data *data)
{
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_v = 0.0;
	data->win = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_data(data), 1);
	if (init_img(data))
		return (1);
	return (0);
}
