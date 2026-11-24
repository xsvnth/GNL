/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <ahmelamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:59:42 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/11/24 21:43:01 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_content(int fd, char *content)
{
	char	*buff;
	ssize_t	readedbytes;

	if (content && nstrchr(content))
		return (content);
	buff = malloc(BUFFER_SIZE + 1);
	readedbytes = 1;
	while (buff && readedbytes > 0 && (!content || !nstrchr(content)))
	{
		readedbytes = read(fd, buff, BUFFER_SIZE);
		if (readedbytes > 0)
		{
			buff[readedbytes] = '\0';
			content = ft_strjoin(content, buff);
			if (!content)
				readedbytes = -1;
		}
	}
	if (!buff || readedbytes < 0)
	{
		free(content);
		content = NULL;
	}
	free(buff);
	return (content);
}

char	*newline_extractor(char *content)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!content[0])
		return (NULL);
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	line = ft_substr(content, 0, len);
	return (line);
}

char	*update_content(char *content)
{
	size_t	i;
	char	*updatedcontent;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	i++;
	updatedcontent = ft_substr(content, i, ft_strlen(content) - i);
	free(content);
	return (updatedcontent);
}

char	*get_next_line(int fd)
{
	static char	*content[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = get_content(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	line = newline_extractor(content[fd]);
	if (!line)
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	content[fd] = update_content(content[fd]);
	return (line);
}
