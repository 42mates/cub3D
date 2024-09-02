/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:56:16 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/02 16:57:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

int		error(char *msg1, char *msg2);

int		parse_elements(t_data *data, char **map, char **tofind);

int		parse_map(t_data *data, char **map);

#endif
