#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	line_len(int fd);

#endif
