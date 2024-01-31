#include "get_next_line.h"

int main()
{
	char *line;
	
	int fd = open("pop", O_RDONLY);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
	line = get_next_line(fd);
	printf("l:%s", line);
}