/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:05:39 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/06 16:35:42 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/src.h"

static void get_view(t_data *data, char c)
{
	if (c == 'N')
		data->dir_v = 0.5f * M_PI;
	else if (c == 'E')
		data->dir_v = 0.0f * M_PI;
	else if (c == 'W')
		data->dir_v = 1.0f * M_PI;
	else if (c == 'S')
		data->dir_v = -0.5f * M_PI;
}

void get_position(t_data *data)
{
	int i;
	int	j;

	i = -1;
	printf("map_h = %d\n", data->map_h);
	while(++i , data->map_h)		// map_h is number of lines in the map
	{
		j = -1;
		while (data->map[i][++j])	// hope lines ended with '\0'
		{
			if (ft_strchr("NEWS", data->map[i][j]))
			{
				data->pos_x = (float) j + 0.5f;	// player's x position
				data->pos_y = (float) i + 0.5f;	// player's y position
				get_view(data, data->map[i][j]);	// get player's view direction
				printf("pos_x = %f, pos_y = %f, dir_v = %f\n", data->pos_x, data->pos_y, data->dir_v);
				return ;
			}
		}
	}
}
