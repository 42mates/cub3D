/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:42:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/09 13:57:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	//while (data->img_txt[++i].img_ptr)
	//{
	//	if (data->img_txt[i].img_ptr)
	//		mlx_destroy_image(data->mlx, data->img_txt[i].img_ptr);
	//	if (data->img_txt[i].d_a)
	//		free(data->img_txt[i].d_a);
	//}
	//if (data->img.img_ptr)
	//	mlx_destroy_image(data->mlx, data->img.img_ptr);

	freentab(data->textures, 4, FALSE);
	freetab(data->map, TRUE);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}