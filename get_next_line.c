/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <ahmelamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:59:42 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/11/18 22:17:23 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_content(int fd, char *content)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	readedbytes;
	char	*tmp;

	readedbytes = read(fd, buff, BUFFER_SIZE);
	if (readedbytes <= 0)
	{
		if (!readedbytes && (!content || content[0] == '\0'))
		{
			free(content);
			return (NULL);
		}
		return (content);
	}
	buff[readedbytes] = '\0';
	tmp = content;
	content = ft_strjoin(content, buff);
	free(tmp);
	if (!ft_strchr(content, '\n'))
		content = get_content(fd, content);
	return (content);
}

char	*newline_extractor(char *content)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!content || !content[0])
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
	if (!content)
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	else if (content[i] == '\n')
		i++;
	updatedcontent = ft_substr(content, i, ft_strlen(content) - i);
	free(content);
	return (updatedcontent);
}

char	*get_next_line(int fd)
{
	static char	*content[1024];
	char		*line;

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
