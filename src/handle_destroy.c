/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:42:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/11 11:54:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

void	free_data(t_data *data)
{
	if (data->textures[0])
		free(data->textures[0]);
	if (data->textures[1])
		free(data->textures[1]);
	if (data->textures[2])
		free(data->textures[2]);
	if (data->textures[3])
		free(data->textures[3]);
	if (data->map)
		freetab(data->map, TRUE);
}

int	handle_destroy(t_data *data)
{
	free_data(data);
	mlx_destroy_image(data->mlx, data->img_txt[0].img_ptr);
	mlx_destroy_image(data->mlx, data->img_txt[1].img_ptr);
	mlx_destroy_image(data->mlx, data->img_txt[2].img_ptr);
	mlx_destroy_image(data->mlx, data->img_txt[3].img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
