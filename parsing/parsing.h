/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:56:16 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 17:24:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

int		error(char *msg1, char *msg2);

int		parse_elements(char **map, t_data *data);

int		parse_map(char **map, t_data *data, int map_start);

#endif
