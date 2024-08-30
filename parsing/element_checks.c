/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:45:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 15:46:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

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

int	check_color(char *elem_name, char *color)
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
