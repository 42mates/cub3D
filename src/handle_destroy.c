/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:42:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/10 16:41:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

void	free_data(t_data *data)
{
	freentab(data->textures, 4, FALSE);
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
