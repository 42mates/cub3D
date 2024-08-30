/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:56:16 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 17:06:45 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

int		error(char *msg1, char *msg2);

int		init_data(t_data *data);

int		check_path(char *elem_name, char *path);
int		check_color(char *elem_name, char *color);

#endif
