/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:41:56 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 17:23:54 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	error(char *msg1, char *msg2)
{
	write(2, "Error\n", 6);
	write(2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME));
	write(2, ": ", 2);
	write(2, msg1, ft_strlen(msg1));
	if (msg2)
	{
		write(2, ": ", 2);
		write(2, msg2, ft_strlen(msg2));
	}
	write(2, "\n", 1);
	return (1);
}

int	parse_file(t_data *data)
{
	char	**map;
	int		map_start;

	map = get_file(data->mapfd);
	if (!map)
		return (error("init_data()", "error retrieving file"));
	close(data->mapfd);
	map_start = parse_elements(map, data);
	if (map_start == -1)
		return (freetab(map, TRUE), 1);
	if (parse_map(map, data, map_start))
		return (freetab(map, TRUE), 1);
	freetab(map, TRUE);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	char	*ptr;

	if (ac < 2)
		return (error("too few arguments", NULL));
	else if (ac > 2)
		return (error("too many arguments", NULL));
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
	ptr = ft_strrstr(av[1], ".cub");
	if (!ptr || ft_strlen(ptr) != 4)
		return (error("invalid map", NULL));
	data->mapfd = open(av[1], O_RDONLY);
	if (data->mapfd == -1)
		return (error(av[1], strerror(errno)));
	if (parse_file(data))
		return (1);
	return (0);
}
