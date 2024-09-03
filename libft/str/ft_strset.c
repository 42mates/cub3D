/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:40:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/03 14:29:24 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/**
 * Searches for the first occurrence of any character from the set 
 * in the given string.
 *
 * @param s The string to search in.
 * @param set The set of characters to search for.
 * @return The adress of the first char of `set` found in s, or NULL otherwise.
 */
char	*ft_strset(char *s, char *set)
{
	int	i;

	if (!s)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (set[i])
		{
			if (*s == set[i++])
				return (s);
		}
		s++;
	}
	return (NULL);
}
