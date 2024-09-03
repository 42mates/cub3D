/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:13 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 17:22:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/**
 * @brief Finds the first occurrence of a substring in a string.

 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @return A pointer to the first occurrence of `needle`, or NULL if not found.
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(&haystack[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Finds the last occurrence in n bytes of a substring in a string.

 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @param n The number of bytes to search in.
 * @return A pointer to the last occurrence of `needle`, or NULL if not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!n)
		return (NULL);
	while (haystack[i] && n > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && n > 0)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			n--;
		}
		i++;
		n += j;
		n--;
	}
	return (NULL);
}

/**
 * @brief Finds the last occurrence of a substring in a string.

 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @return A pointer to the last occurrence of `needle`, or NULL if not found.
 */
char	*ft_strrstr(const char *haystack, const char *needle)
{
	char	*ptr;
	char	*next;

	next = ft_strstr(haystack, needle);
	ptr = next;
	while (next)
	{
		ptr = next;
		next = ft_strstr(ptr + 1, needle);
	}
	return (ptr);
}
