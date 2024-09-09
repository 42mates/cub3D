/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:38:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/09 13:46:06 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"

char	**get_rgb_tab(char **val)
{
	char	**rgb;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	rgb = ft_split(val[i++], ',');
	while (val[i])
	{
		j = 0;
		tmp = ft_split(val[i], ',');
		if (!tmp)
			return (error("(debug) get_rgb_tab", "ft_split failed"), NULL);
		while (tmp[j])
			rgb = ft_tabjoin(rgb, tmp[j++], TRUE, FALSE);
		freetab(tmp, TRUE);
		i++;
	}
	return (rgb);
}

int	has_multiple_players(char to_check)
{
	static char	player[4] = "NSWE";

	if (!ft_is(to_check, "NSWE"))
		return (0);
	if (!player[0])
		return (error("invalid map", "multiple players"));
	player[0] = 0;
	return (0);
}

int	is_valid_ground(char **map, int i, int j)
{
	if (j == 0 && ft_is(map[i][j], "0NSWE"))
		return (0);
	else if (j != 0 && ft_is(map[i][j], "0NSWE")
		&& (!ft_is(map[i][j - 1], "01NSWE")
		|| !ft_is(map[i][j + 1], "01NSWE")
		|| !ft_is(map[i - 1][j], "01NSWE")
		|| !ft_is(map[i + 1][j], "01NSWE")))
		return (0);
	return (1);
}

void	remove_nl(char **map)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(map[i++], '\n');
	while (tmp)
	{
		*tmp = 0;
		tmp = ft_strchr(map[i++], '\n');
	}
}
