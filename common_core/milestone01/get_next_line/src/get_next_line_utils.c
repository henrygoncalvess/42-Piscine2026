/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:26:44 by hegoncal          #+#    #+#             */
/*   Updated: 2026/07/22 17:46:35 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// REMOVE REMOVE REMOVE REMOVE
#include <stdio.h>

// REMOVE REMOVE REMOVE REMOVE

size_t	line_len(int fd)
{
	char	buffer[1024];
	size_t	bytes_read;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			printf("%c", buffer[i]);
			if (buffer[i] == '\n')
				return (line_len);
			i++;
			line_len++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line_len);
}
