/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:11:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/30 17:08:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

/**
 * @brief Finds a string in an array of strings.
 *
 * @param needle The string to search for.
 * @param haystack The array of strings to search in.
 * @return The array index of the string found, or -1 if not found.
 */
int	ft_tabfind(char *needle, char **haystack)
{
	int	i;

	i = 0;
	if (!needle || !haystack)
		return (0);
	while (haystack[i])
	{
		if (!ft_strcmp(needle, haystack[i]))
			return (i);
		i++;
	}
	return (-1);
}
