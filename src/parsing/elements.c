/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:28:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/09 13:47:28 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"

int	rgb_to_int(char **val)
{
	char	**rgb;
	int		color;
	int		rgb_int;
	int		i;

	rgb = get_rgb_tab(val + 1);
	if (!rgb)
		return (error("(debug) rgb_to_int", "get_rgb_tab failed"), -1);
	i = 0;
	rgb_int = 0;
	while (i < 3)
	{
		color = atoi(rgb[i++]);
		rgb_int = (rgb_int << 8) + color;
	}
	freetab(rgb, TRUE);
	return (rgb_int);
}

/**
 * @brief Check the validity of a texture path.
 * 
 * @param elem_name The name of the element being checked.
 * @param color The color string to be checked.
 * @return 0 if the path is valid, otherwise 1.
 */
int	check_path(char *elem_name, char *path)
{
	int		fd;
	char	*ptr;

	if (!path)
		return (error(elem_name, "no path found"));
	ptr = ft_strrstr(path, ".xpm");
	if (!ptr || ft_strlen(ptr) != 4)
		return (error(path, "invalid texture file"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error(path, strerror(errno)));
	close(fd);
	return (0);
}

/**
 * @brief Check the validity of a color string.
 * 
 * @param elem_name The name of the element being checked.
 * @param color The color string to be checked.
 * @return 0 if the color is valid, otherwise 1.
 */
int	check_color(char **val)
{
	char	**rgb;
	int		i;

	if (!val[1])
		return (error(val[0], "no color found")); 
	rgb = get_rgb_tab(val + 1);
	if (ft_tablen(rgb) != 3)
	{
		freetab(rgb, TRUE);
		return (error(val[0], "invalid color format (3 values required)"));
	}
	i = -1;
	while (++i < 3)
	{
		if (!ft_isnum(rgb[i]) || ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			freetab(rgb, TRUE);
			error(val[0], "invalid color format (Out of range or NaN)");
			return (1);
		}
	}
	freetab(rgb, TRUE);
	return (0);
}

/**
 * @brief Checks the validity of an element and updates the data structure 
 * accordingly.
 * @param val The element value in the format "{<name>, <value>}".
 * @param data The data structure to update.
 * @return 0 if the element is valid and updated successfully, 1 otherwise.
 */
int	check_element(char **val, t_data *data, char **tofind)
{
	int			i;

	if (ft_tablen(val) < 2 || (ft_is(**val, "NSWE") && ft_tablen(val) != 2))
		return (error(val[0], "invalid line format"));
	i = ft_tabfind(val[0], tofind);
	if (i >= 0)
	{
		if (i < 4 && !check_path(val[0], val[1]))
			data->textures[i] = ft_strdup(val[1]);
		else if (i >= 4 && !check_color(val))
			data->colors[i % 4] = rgb_to_int(val);
		else
			return (1);
		tofind[i][0] = 0;
		i++;
		return (0);
	}
	else
		return (error(val[0], "element unknown or already defined"));
	return (1);
}

/**
 * @brief Parses the elements in the map and stores them in the data structure.

 * @param map The map to parse.
 * @param data The data structure to store the elements.
 * @return the index of the first non-empty line if the map is found, -1 
 * otherwise.
 */
int	parse_elements(t_data *data, char **map, char **tofind)
{
	char		**val;
	int			i;
	int			values_stored;

	i = -1;
	values_stored = 0;
	while (map[++i])
	{
		if (!*avoid_space(map[i], TRUE))
			continue ;
		if (*avoid_space(map[i], TRUE) == '1' && values_stored == 6)
			return (i);
		else if (*avoid_space(map[i], TRUE) == '1' && values_stored != 6)
			return (error("missing map element", NULL), -1);
		val = ft_split_charset(map[i], SPACES_NL);
		if (check_element(val, data, tofind))
		{
			freetab(val, TRUE);
			return (-1);
		}
		freetab(val, TRUE);
		values_stored++;
	}
	return (error("no map found", NULL), -1);
}
