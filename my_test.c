// #include "get_next_line.h"
#include "get_next_line_bonus.h"

int main()
{
	char *line;
	
	int fd;
	fd = open("zig", O_RDONLY);
	line = get_next_line(fd);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd);
	printf("<<<%s>>>", line);
	free(line);
	line = get_next_line(fd);
	printf("<<<%s>>>", line);
	free(line);
}