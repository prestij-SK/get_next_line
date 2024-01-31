#include "get_next_line.h"

static char	*cut_next_line_from_text(char *file_text)
{
	char	*new_text;
	size_t	i;

	if (!file_text)
		return (NULL);
	if (!(*file_text))
	{
		free(file_text);
		return (NULL);
	}
	i = 0;
	while (file_text[i] && file_text[i] != '\n')
		++i;
	new_text = substr_alt(file_text, i + 1, strlen_alt(file_text) - i);
	// printf("nt:%s$", new_text);
	free(file_text);
	return (new_text);
}

static char	*add_to_left(char *file_text, char *line, size_t file_text_len, size_t line_len)
{
	char	*new_file_text;
	size_t	i;

	if (!file_text_len && !line_len)
		return (NULL);
	new_file_text = (char *)malloc(sizeof(char) * (file_text_len + line_len + 1));
	if (!new_file_text)
		return (NULL);
	i = 0;
	while (i < file_text_len)
	{
		new_file_text[i] = file_text[i];
		++i;
	}
	i = 0;
	while (i < line_len)
	{
		new_file_text[file_text_len + i] = line[i];
		++i;
	}
	// printf("[_%zu_]\n", file_text_len);
	// printf("<-%zu->\n", line_len);
	return (new_file_text);
}

static char	*read_text_from_file(const int fd)
{
	char	*buffer;
	char	*new_file_text;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	new_file_text = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_file_text);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		new_file_text = add_to_left(new_file_text, buffer, strlen_alt(new_file_text), strlen_alt(buffer));
	}
	free(buffer);
	return (new_file_text);
}

char	*get_next_line(int fd)
{
	static char	*file_text;
	char		*next_line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file_text)
		file_text = read_text_from_file(fd);
	if (!file_text)
		return (NULL);
	if (!(*file_text))
	{
		free(file_text);
		file_text = NULL;
		return (NULL);
	}
	i = 0;
	while (file_text[i] && file_text[i] != '\n')
		++i;
	next_line = substr_alt(file_text, 0, i + 1);
	file_text = cut_next_line_from_text(file_text);
	return (next_line);
}