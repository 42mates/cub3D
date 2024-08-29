/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:05:39 by akurochk          #+#    #+#             */
/*   Updated: 2024/08/29 14:22:59 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void get_view(t_data *data, char c)
{
	if (c == 'N')
		data->dir_v = 0.5f * M_PI;
	else if (c == 'E')
		data->dir_v = 0.0f;
	else if (c == 'W')
		data->dir_v = M_PIf
	else if (c == 'S')
		data->dir_v = -0.5f * M_PI;
}

void get_position(t_data *data) 
{
	int i;
	int	j;

	i = -1;
	while(++i , data->map_l)		// map_l is number of lines in the map
	{
		j = -1;
		while (data->map[i][++j])	// hope line ended with '\0'
		{
			if (ft_strchr("NEWS", data->map[i][j]))
			{
				data->pos_x = (float)j + 0.5f;	// player's x position
				data->pos_y = (float)i + 0.5f;	// player's y position
				get_view(data, data->map[i][j]);	// get player's view direction
				return ;
			}
		}
	}
}
