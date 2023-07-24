/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:24:48 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 21:12:24 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*buf;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	buf = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!buf)
	{
		free(s1);
		return (NULL);
	}
	gnl_strlcpy (buf, s1, len1 + 1);
	gnl_strlcpy (buf + len1, s2, len2 + 1);
	free(s1);
	return (buf);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	x;

	if (start >= gnl_strlen (s))
		return (0);
	else if (gnl_strlen(s) - start < len)
		x = gnl_strlen(s) - start;
	else
		x = len;
	buf = malloc (x + 1);
	if (buf == NULL)
		return (NULL);
	gnl_strlcpy(buf, s + start, len + 1);
	return (buf);
}
