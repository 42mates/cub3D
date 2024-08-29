/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 17:26:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_map_elem
{
	char	*no; //north texture path
	char	*so; //south texture path
	char	*we; //west texture path
	char	*ea; //east texture path
	int		f; //floor rgb value
	int		c; //ceiling rgb value
}		t_map_elem;

typedef struct s_data
{
	int			mapfd;
	char		**map;
	t_map_elem	txtr;
}				t_data;

#endif
