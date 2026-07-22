/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:41:42 by hegoncal          #+#    #+#             */
/*   Updated: 2026/07/22 17:45:32 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// REMOVE REMOVE REMOVE REMOVE
#include <fcntl.h>
#include <stdio.h>

// REMOVE REMOVE REMOVE REMOVE
// cc -Wall -Wextra -Werror -I ../includes get_next_line.c get_next_line_utils.c

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	char	*line_content;
	size_t	bytes_read;

	if (fd == -1 || fd == 0)
		return (NULL);
	printf("ll: %zu\n", line_len(fd));
	line_content = malloc(line_len(fd) * sizeof(char));
	if (line_content == NULL)
		return (NULL);
	bytes_read = read(fd, line_content, BUFFER_SIZE);
	printf("fl: %s\n", line_content);
	while (bytes_read > 0)
		bytes_read = read(fd, line_content, BUFFER_SIZE);
	close(fd);
	return (line_content);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
