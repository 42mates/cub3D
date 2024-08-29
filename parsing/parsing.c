/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:41:56 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/28 18:44:40 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_path(char *elem_name, char *line)
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
int	get_texture(char **map, char *elem_name)
{
	char	*path;
	int		fd;
	int		i;

	i = -1;
	while (map[++i])
	{
		path = get_texture_path(elem_name, map[i]);
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

int	encode_color(char *input)
{
	char	**values;
	int		color;
	int		rgb;
	int		i;

	i = 0;
	values = ft_split(input, ',');
	rgb = 0;
	if (!values)
		return (-1);
	if (ft_tablen(values) != 3)
		return (freetab(values, TRUE), -1);
	while (i < 3)
	{
		if (!ft_isnum(values[i]))
			return (freetab(values, TRUE), -1);
		color = atoi(values[i]);
		if (color < 0 || color > 255)
			return (freetab(values, TRUE), -1);
		rgb = (rgb << 8) + color;
	}
	return (rgb);
}

int	get_color(char **map, char *elem_name)
{
	char	*ptr;
	int		color;
	int		i;

	i = -1;
	while (map[++i])
	{
		ptr = ft_strstr(map[i], elem_name);
		if (!ptr)
			return (-1);
		ptr += ft_strlen(elem_name);
		while (ft_is(*ptr, " \t\r\f\v"))
			ptr++;
		color = encode_color(ptr);
		if (color >= 0 && color <= 255)
			break ;
	}
	if (color < 0 || color > 255)
	{
		write(2, "Error: '", 8);
		write(2, elem_name, ft_strlen(elem_name));
		write(2, "' invalid or not found\n", 23);
		return (-1);
	}
	return (color);
}



int	get_elem(t_data *data)
{
	char		**map;

	map = get_file(data->mapfd);
	if (!map)
		return (write(2, "get_elem(): error retrieving file", 32), 1);
	
	return (printtab(map, 1), 0);


	//get the textures and colors
	data->txtr.no = get_texture(map, "NO");
	data->txtr.so = get_texture(map, "SO");
	data->txtr.we = get_texture(map, "WE");
	data->txtr.ea = get_texture(map, "EA");
	data->txtr.f = get_color(map, "F");
	data->txtr.c = get_color(map, "C");
	freetab(map, TRUE);
	if (data->txtr.no < 0 || data->txtr.so < 0 || data->txtr.we < 0
		|| data->txtr.ea < 0 || data->txtr.f < 0 || data->txtr.c < 0)
		return (1);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	char	*ptr;
	
	//check arguments count
	if (ac < 2)
		return (write(2, "cub3d: too few arguments\n", 25), 1);
	else if (ac > 2)
		return (write(2, "cub3d: too many arguments\n", 26), 1);
	
	//check the map file
	ptr = ft_strstr(av[1], ".cub");
	if (!ptr || ft_strlen(ptr) != 4)
		return (write(2, "cub3d: invalid file extension\n", 30), 1);
	data->mapfd = open(av[1], O_RDONLY);
	if (data->mapfd == -1)
		return (perror("cub3d"), 1);
	
	//check and retrieve the map elements
	if (get_elem(data))
		return (1);
	return (0);
}
