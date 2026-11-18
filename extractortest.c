#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lensrc;

	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	if (!size)
		return (lensrc);
	while (--size && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (lensrc);
}

char	*newline_extractor(char *stash)
{
	size_t	len;
	char	*line;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, len + 1);
	return (line);
}
int	main(void)
{
	char	*stash;
	char	*line;

	stash = "prazima \nconrasau senta \ndona fala qe si semento\n\0";
	line = newline_extractor(stash);
	printf("%s\n", line);
}
