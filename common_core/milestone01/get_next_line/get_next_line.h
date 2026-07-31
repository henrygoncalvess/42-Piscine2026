/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 23:06:06 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/19 23:26:25 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# define DELIMITER '\n'

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *src);
size_t	gnl_strlen(const char *s);
char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*get_remaining(char *stash);

char	*get_next_line(int fd);

#endif
