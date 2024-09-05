/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:59:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/05 12:50:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../libft.h"

void	freetab(char **tab, int heap);
void	freentab(char **tab, int n, int heap);

#endif