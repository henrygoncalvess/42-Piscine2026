/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:26:44 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/19 23:24:44 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free((char *)s1);
	return (new_str);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*str_arr;

	len = 0;
	while (src[len])
		len++;
	str_arr = malloc((len + 1) * sizeof(char));
	if (str_arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_arr[i] = src[i];
		i++;
	}
	str_arr[i] = '\0';
	return (str_arr);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	str_len;
	unsigned int	i;

	str_len = 0;
	while (s[str_len])
		str_len++;
	if (start >= str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
