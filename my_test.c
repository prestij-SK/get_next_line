#include "get_next_line.h"

int main()
{
	char *line;
	
	int fd[3];
	fd[0] = open("zig", O_RDONLY);
	fd[1] = open("dog", O_RDONLY);
	fd[2] = 1000;
	line = get_next_line(fd[0]);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd[2]);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd[0]);
	printf("<<<%s>>>", line);
	free(line);
}