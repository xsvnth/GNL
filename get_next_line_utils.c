/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <ahmelamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:19:09 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/11/21 03:16:18 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*nstrchr(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1);
	ret = malloc(len + ft_strlen(s2) + 1);
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = ft_strlen(s);
	if (start >= i)
		len = 0;
	else if (len > i - start)
		len = i - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
