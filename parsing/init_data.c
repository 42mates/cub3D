/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:28:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 17:07:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	rgb_to_int(char *rgb_str)
{
	char	**values;
	int		color;
	int		rgb_int;
	int		i;

	if (!rgb_str)
		return (-1);
	values = ft_split(rgb_str, ',');
	if (!values)
		return (error("(debug) rgb_to_int", "ft_split failed"), -1);
	i = 0;
	rgb_int = 0;
	while (i < 3)
	{
		color = atoi(values[i++]);
		rgb_int = (rgb_int << 8) + color;
	}
	freetab(values, TRUE);
	return (rgb_int);
}

int	check_element(char **val, t_data *data)
{
	static char	*elem[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	static int	i = 0;

	if (ft_tablen(val) != 2)
		return (error(val[0], "invalid line format"));
	if (!ft_strcmp(val[0], elem[i]))
	{
		if (i < 4 && !check_path(val[0], val[1]))
			data->textures[i] = ft_strdup(val[1]);
		else if (i >= 4 && !check_color(val[0], val[1]))
			data->colors[i % 4] = rgb_to_int(val[1]);
		else
			return (1);
		i++;
		return (0);
	}
	if (ft_tabfind(val[0], elem) >= 0)
		return (error(val[0], "element in wrong order or already defined"));
	error(val[0], "unknown element");
	return (1);
}

int	get_elements(char **map, t_data *data)
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
		if (*avoid_space(map[i], TRUE) == '1')
			return (i);
		val = ft_split_charset(map[i], SPACES_NL);
		if (check_element(val, data))
		{
			freetab(val, TRUE);
			return (-1);
		}
		freetab(val, TRUE);
		values_stored++;
	}
	if (values_stored != 6)
		return (error("missing map element", NULL), -1);
	return (error("no map found", NULL), -1);
}

int	init_data(t_data *data)
{
	char	**map;
	int		map_start;

	map = get_file(data->mapfd);
	if (!map)
		return (error("init_data()", "error retrieving file"));
	close(data->mapfd);
	map_start = get_elements(map, data);
	if (map_start == -1)
		return (freetab(map, TRUE), 1);
	freetab(map, TRUE);
	return (0);
}
