/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:28:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 17:51:31 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	check_path(char *path, char *elem_name)
{
	int		fd;
	char	*ptr;

	if (!path)
		return (error(elem_name, "no path found"));
	// check the file extension
	ptr = ft_strrstr(path, ".xpm");
	if (!ptr || ft_strlen(ptr) != 4)
		return (error(path, "invalid texture file"));
	// check if the file opens
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error(path, strerror(errno)));
	close(fd);
	return (0);
}

int	check_color(char *color, char *elem_name)
{
	char	**rgb;
	int		i;

	if (!color)
		return (error(elem_name, "no color found"));
	if (ft_strlen(color) > 11)
		return (error(elem_name, "invalid color format (string too long)"));
	rgb = ft_split(color, ',');
	if (!rgb || ft_tablen(rgb) != 3)
	{
		freetab(rgb, TRUE);
		return (error(elem_name, "invalid color format (3 values required)"));
	}
	i = -1;
	while (++i < 3)
	{
		if (!ft_isnum(rgb[i]) || ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			freetab(rgb, TRUE);
			error(elem_name, "invalid color format (Out of range or NaN)");
			return (1);
		}
	}
	freetab(rgb, TRUE);
	return (0);
}

/**
 * @brief Retrieves the value in the map and checks if it opens.
 *
 * @param map The map containing the elements.
 * @param elem_name The name of the element to search for (NO, WE, F).
 * @return The file path of the specified element, or NULL if not found.
 */
char	*get_value(char **map, char *elem_name, int (*f_check)(char *, char *))
{
	char	*val;
	char	*end;
	int		i;

	i = -1;
	while (map[++i])
	{
		val = avoid_space(map[i], TRUE);
		if (!ft_strncmp(val, elem_name, ft_strlen(elem_name)))
		{
			val = avoid_space(val + ft_strlen(elem_name), TRUE);
			end = val;
			while (ft_isprint(*end) && *end != ' ')
				end++;
			val = ft_substr(val, 0, end - val);
			if (f_check(val, elem_name))
				return (free(val), NULL);
			return (val);
		}
	}
	error(elem_name, "element not found");
	return (NULL);
}

int	rgb_to_int(char *input)
{
	char	**values;
	int		color;
	int		rgb;
	int		i;

	if (!input)
		return (-1);
	values = ft_split(input, ',');
	if (!values)
		return (error("(debug) rgb_to_int", "ft_split failed"), -1);
	i = 0;
	rgb = 0;
	while (i < 3)
	{
		color = atoi(values[i++]);
		rgb = (rgb << 8) + color;
	}
	free(input);
	freetab(values, TRUE);
	return (rgb);
}

int	get_elements(t_data *data)
{
	char	**map;

	map = get_file(data->mapfd);
	if (!map)
		return (error("get_elements()", "error retrieving file"));
	close(data->mapfd);
	data->txtr.no = get_value(map, "NO", &check_path);
	data->txtr.so = get_value(map, "SO", &check_path);
	data->txtr.we = get_value(map, "WE", &check_path);
	data->txtr.ea = get_value(map, "EA", &check_path);
	data->txtr.f = rgb_to_int(get_value(map, "F", &check_color));
	data->txtr.c = rgb_to_int(get_value(map, "C", &check_color));
	freetab(map, TRUE);
	if (!data->txtr.no || !data->txtr.so || !data->txtr.we || !data->txtr.ea
		|| data->txtr.f < 0 || data->txtr.c < 0)
		return (1);
	return (0);
}
