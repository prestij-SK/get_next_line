#include "get_next_line_bonus.h"

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

size_t	strlen_with_enter(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	return (i);
}

static void	strcpy_alt(char *dest, const char *src, size_t *i)
{
	if (!dest || !src)
		return ;
	while (*src)
	{
		dest[*i] = *src;
		++src;
		++(*i);
	}
}

char	*strjoin_to_left(const char *s1, const char *s2)
{
	size_t	i;
	char	*str_new;

	if (!s2)
		return (NULL);
	str_new = (char *)malloc((sizeof(char)
				* (strlen_alt(s1) + strlen_alt(s2))) + 1);
	if (!str_new)
		return (NULL);
	i = 0;
	strcpy_alt(str_new, s1, &i);
	strcpy_alt(str_new, s2, &i);
	str_new[i] = '\0';
	return (str_new);
}