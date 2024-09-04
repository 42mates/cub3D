/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:38:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/04 17:56:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

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
