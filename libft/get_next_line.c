/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:46:35 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 20:58:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	read_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + 1);
}

char	*read_str(int fd, char *s)
{
	char	*d;
	int		len;

	d = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!d)
		return (NULL);
	len = 1;
	while (!gnl_strchr(s, '\n') && len != 0)
	{
		len = read(fd, d, BUFFER_SIZE);
		if (len == -1)
		{
			free (d);
			free(s);
			return (NULL);
		}
		d[len] = '\0';
		s = gnl_strjoin(s, d);
	}
	free (d);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*s;
	static char	*sr;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_str(fd, sr);
	if (!s)
	{
		sr = NULL;
		return (NULL);
	}
	i = read_line(s);
	sr = gnl_substr(s, i, gnl_strlen(s) - i);
	line = gnl_substr(s, 0, i);
	free(s);
	return (line);
}