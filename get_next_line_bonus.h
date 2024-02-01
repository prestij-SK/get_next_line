#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h> // DELETE
#include <stdio.h> // DELETE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef DESCRIPTER_COUNT
#  define DESCRIPTER_COUNT 4096
# endif

char	*get_next_line(int fd);
size_t	strlen_alt(const char *s);
char	*strjoin_to_left(const char *s1, const char *s2);
size_t	strlen_with_enter(const char *str);

#endif