/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:02:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/05 12:50:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

/**
 * @brief Frees the content of an array of char *.
 * @param tab The tab to free.
 * @param heap If 1, frees the tab itself.
 */
void	freetab(char **tab, int heap)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (heap)
		free(tab);
}

/**
 * @brief Frees the content of an array of char * for `n` rows.
 * @param tab The tab to free.
 * @param n The number of rows to free.
 * @param heap If 1, frees the tab itself.
 */
void	freentab(char **tab, int n, int heap)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] && i < n)
	{
		free(tab[i]);
		i++;
	}
	if (heap)
		free(tab);
}
