#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h> // DELETE
#include <stdio.h> // DELETE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
size_t	strlen_alt(const char *s);
char	*substr_alt(char const *s, size_t start, size_t len);

#endif