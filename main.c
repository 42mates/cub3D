/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/04 17:58:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
		free(data->textures[i++]);
	freetab(data->map, TRUE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data))
		return (free_data(&data), 1);
	//init_data(&data);

	//open textures and free textures
	open_textures(&data) //CREATE ME

	//get player position
	get_position(t_data *data);

	main_loop(&data);
	//freetab(data.map, TRUE); // DELETE ME

	//free_data(&data);
	//mlx destroy texture images and window 
	return (0);
}
