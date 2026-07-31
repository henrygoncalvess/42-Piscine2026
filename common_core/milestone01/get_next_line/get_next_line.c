/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:41:42 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/22 16:29:42 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = gnl_strdup("");
	if (!gnl_strchr(stash, DELIMITER))
		stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = get_remaining(stash);
	return (line);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (gnl_strchr(buffer, DELIMITER))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*delimiter_pos;
	size_t	len;

	delimiter_pos = gnl_strchr(stash, DELIMITER);
	if (delimiter_pos)
		len = (size_t)(delimiter_pos - stash) + 1;
	else
		len = gnl_strlen(stash);
	return (gnl_substr(stash, 0, len));
}

char	*get_remaining(char *stash)
{
	char	*delimiter_pos;
	char	*remaining;

	delimiter_pos = gnl_strchr(stash, DELIMITER);
	if (!delimiter_pos)
	{
		free(stash);
		return (gnl_strdup(""));
	}
	remaining = gnl_strdup(delimiter_pos + 1);
	free(stash);
	return (remaining);
}
