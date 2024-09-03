/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/03 16:35:15 by mbecker          ###   ########.fr       */
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
	free_data(&data);
	return (0);
}
