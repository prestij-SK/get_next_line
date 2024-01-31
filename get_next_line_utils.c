#include "get_next_line.h"

// Alternative strlen, which is not the same as the standard
size_t	strlen_alt(const char *str)
{
	size_t	i;

	if (!str) // return 0 when NULL
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

// Alternative substr, which is not the same as the standard
char	*substr_alt(char const *str, size_t start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*substr;

	if (!str)
		return (NULL);
	str_len = strlen_alt(str);
	if (str_len < start)
		len = 0;
	if ((str_len - start) < len)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len) && (start + i < str_len))
	{
		substr[i] = str[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}