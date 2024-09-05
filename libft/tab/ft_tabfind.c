/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:11:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/05 16:26:04 by mbecker          ###   ########.fr       */
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

/**
 * Finds the first occurrence of a substring in an array of strings.
 *
 * @param needle The substring to search for.
 * @param haystack The array of strings to search in.
 * @return A pointer to the first occurrence of the substring in the array of 
 * strings, or NULL if the substring is not found.
 */
char	*ft_tabstr(char *needle, char **haystack)
{
	int		i;
	char	*res;

	i = 0;
	if (!needle || !haystack)
		return (0);
	while (haystack[i])
	{
		res = ft_strstr(haystack[i], needle);
		if (res)
			return (res);
		i++;
	}
	return (NULL);
}
