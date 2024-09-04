/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:45:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/04 17:56:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	check_empty(char **map, int *map_end)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strset(map[i], "01NSWE");
	while (tmp && *tmp)
		tmp = ft_strset(map[++i], "01NSWE");
	*map_end = i;
	tmp = avoid_space(map[i], TRUE);
	while (map[i] && tmp)
	{
		tmp = avoid_space(map[i], TRUE);
		if (tmp && *tmp)
			return (error("invalid map", "empty lines detected"));
		i++;
	}
	return (0);
}

int	check_top_bottom(char **map, int map_end)
{
	int	i;
	int	last;

	i = 0;
	while (ft_is(map[0][i], " 1"))
		i++;
	if (map[0][i] != '\n' || map[0][i + 1])
		return (error("invalid map", "please check top border"));
	last = map_end - 1;
	i = 0;
	while (ft_is(map[last][i], " 1"))
		i++;
	if (map[last][i] != '\n' && map[last][i] != 0)
		return (error("invalid map", "please check bottom border"));
	return (0);
}

int	check_middle(char **map, int map_end)
{
	int	i;
	int	j;
	int	has_player;

	i = 0;
	has_player = 0;
	while (map[++i] && i < map_end)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is(map[i][j], "NSWE"))
				has_player = 1;
			if (!ft_is(map[i][j], " 01NSWE\n"))
				return (error("invalid map", "forbidden character"));
			else if (!is_valid_ground(map, i, j))
				return (error("invalid map", "breach found"));
			else if (has_multiple_players(map[i][j]))
				return (1);
			j++;
		}
	}
	if (!has_player)
		return (error("invalid map", "no player"));
	return (0);
}

int	parse_map(t_data *data, char **map)
{
	int		map_end;

	if (check_empty(map, &map_end))
		return (1);
	if (map_end < 3)
		return (error("invalid map", "too small"));
	if (check_top_bottom(map, map_end)
		|| check_middle(map, map_end))
		return (1);
	data->map = ft_tabndup(map, map_end);
	if (!data->map)
		return (error("parse_map()", "error duplicating map"));
	return (0);
}
