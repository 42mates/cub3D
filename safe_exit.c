/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:06:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 12:00:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	safe_exit(t_data *data)
{
	free(data->txtr.no);
	free(data->txtr.so);
	free(data->txtr.we);
	free(data->txtr.ea);
}
