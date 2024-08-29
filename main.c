/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 13:23:16 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_pathx(char *elem_name, char *line)
{
	char	*path;
	int		i;

	path = ft_strstr(line, elem_name);
	if (!path)
		return (NULL);
	path += ft_strlen(elem_name);
	while (ft_is(*path, " \t\r\f\v"))
		path++;
	i = 0;
	while (!ft_isprint(path[i]) || path[i] != ' ')
		i++;
	path = ft_strndup(path, i);
	return (path);
}

/**
 * @brief Retrieves the file descriptor of a texture in the map.
 *
 * @param map The map containing the elements.
 * @param elem_name The name of the element to search for (NO, WE, F).
 * @return The file descriptor of the specified element, or -1 if not found.
 */
int	get_texturex(char **map, char *elem_name)
{
	char	*path;
	int		fd;
	int		i;

	i = -1;
	while (map[++i])
	{
		path = get_texture_pathx(elem_name, map[i]);
		printf("path: '%s'\n", path);
		fd = open(path, O_RDONLY);
		free(path);
		if (fd >= 0)
			break ;
	}
	if (fd < 0)
	{
		write(2, "Error: '", 8);
		write(2, elem_name, ft_strlen(elem_name));
		write(2, "' invalid or not found\n", 23);
		return (-1);
	}
	return (fd);
}

int	main(int ac, char **av)
{
	char *map[] = {
		"NO ./ok.cub\n",
		"SO ./ok.cub  \n",
		"WE      ./ok.cub    \n",
		"EA ./ok.cub       ",
		//"F 255,255,255",
		//"C 0,0,0     ",
		NULL
	};

	printf("NO: %d\n", get_texturex(map, "NO"));
	printf("SO: %d\n", get_texturex(map, "SO"));
	printf("WE: %d\n", get_texturex(map, "WE"));
	printf("EA: %d\n", get_texturex(map, "EA"));

	return (0);

	t_data data;

	// init_data(&data);
	// args_check(ac, av, &data)
	parsing(ac, av, &data);
	main_loop(&data);

	return (0);
}
