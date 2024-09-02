/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:45:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/02 18:29:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	check_mapline(char *line)
{
	int	i;

	i = 0;
	if (!ft_is(line[i], " 1"))
		return (error("invalid map", "breach found in left border"));
	while (line[++i])
	{
		//if (!ft_is(line[i], " 01NSWE"))
		//	return (error("invalid map", "forbidden character"));
		//else if (line[i] == '0' && !ft_is(line[i - 1], "1"))
		//	return (error("invalid map", "breach found in left border"));
		//else if (line[i] == '0' && !ft_is(line[i + 1], "1"))
		//	return (error("invalid map", "breach found in left border"));
	}
	return (0);
}

int	parse_map(t_data *data, char **map)
{
	int		i;
	long	player_pos;

	(void)data;
	if (ft_strset(map[0], "0NSWE"))
		return (error("invalid map", "breach found in top border"));
	else if (ft_strset(map[ft_tablen(map) - 1], "0NSWE"))
		return (error("invalid map", "breach found in bottom border"));

	i = 0;
	player_pos = -1;
	while (map[++i] && player_pos < 0)
		player_pos = ft_strset(map[i], "NSWE") - map[i];
	
	//ft_dfs(data, i, player_pos, "0NSWE");

	//data->map = ft_tabdup(map);
	//if (!data->map)
	//	return (error("parse_map()", "error duplicating map"));

	
	return (0);
}
