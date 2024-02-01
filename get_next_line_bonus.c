#include "get_next_line_bonus.h"

static size_t	next_line_length(const char *str)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1); // has '\n'
		++i;
	}
	return (0); // has no '\n'
}

 // I have to add these (read_bytes) and (line_length) parameters for norminatte pass
static char	*read_from_file(const int fd, size_t read_bytes, ssize_t line_length)
{
	char	*buffer;
	char	*temp_text;
	char	*final_text;

	final_text = NULL;
	while (read_bytes > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes == 0 && !buffer[0])
		{
			free(buffer);
			break ;
		}
		temp_text = final_text;
		final_text = strjoin_to_left(final_text, buffer);
		free(temp_text);
		line_length = next_line_length(buffer);
		free(buffer);
		if (line_length > 0)
			break ;
	}
	return (final_text);
}

static char	*take_next_line(const char *scanned_text)
{
	char	*next_line;
	size_t	len;
	size_t	i;

	if (!scanned_text)
		return (NULL);
	len = strlen_with_enter(scanned_text);
	next_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!next_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		next_line[i] = scanned_text[i];
		++i;
	}
	next_line[i] = '\0';
	return (next_line);
}

static char *cut_next_line(const char *scanned_text)
{
	char	*new_text;
	size_t	i;

	if (!scanned_text)
		return (NULL);
	i = strlen_with_enter(scanned_text);
	new_text = (char *)malloc(sizeof(char) * (strlen_alt(scanned_text) - i + 1));
	if (!new_text)
		return (NULL);
	scanned_text += i;
	i = 0;
	while (scanned_text[i])
	{
		new_text[i] = scanned_text[i];
		++i;
	}
	new_text[i] = '\0';
	if (!new_text[0])
	{
		free(new_text);
		new_text = NULL;
	}
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*scanned_text[DESCRIPTER_COUNT];
	char		*next_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(scanned_text[fd]);
		scanned_text[fd] = NULL;
		return (NULL);
	}
	if (!(next_line_length(scanned_text[fd])))
	{
		next_line = read_from_file(fd, 1, 0);
		if (next_line)
		{
			temp = scanned_text[fd];
			scanned_text[fd] = strjoin_to_left(scanned_text[fd], next_line);
			free(temp);
			free(next_line);
		}
	}
	if (!scanned_text[fd]) // file is fully scanned
	{
		free(scanned_text[fd]);
		scanned_text[fd] = NULL;
		return (NULL);
	}
	next_line = take_next_line(scanned_text[fd]);
	temp = scanned_text[fd];
	scanned_text[fd] = cut_next_line(scanned_text[fd]);
	free(temp);
	return (next_line);
}