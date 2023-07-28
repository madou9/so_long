/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 22:13:13 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_line(char **xy_map)
{
	int		i;

	i = 0;
	while (xy_map[i])
		i++;
	return (i);
}

int	get_map_size(char *map)
{
	char	*buffer;
	int		total_bytes;
	int		byte_chunks;
	int		fd;

	printf("get_map_size!\n");
	fd = open(map, O_RDONLY);
	total_bytes = 0;
	buffer = malloc (sizeof(int) * 1024);
	byte_chunks = read(fd, buffer, 1024);
	if (!(byte_chunks))
	{
		free (buffer);
		close(fd);
		return (0);
	}
	total_bytes = total_bytes + byte_chunks;
	if (byte_chunks != '\0')
	{
		byte_chunks = read(fd, buffer, 1024);
		total_bytes = total_bytes + byte_chunks;
	}
	close(fd);
	free (buffer);
	return (total_bytes);
}

char	*read_map_file(char *filename)
{
	int		fd;
	int		num_bytes;
	char	*map_buffer;

	printf("read_map_file!\n");
	num_bytes = get_map_size(filename) + 1;
	if (num_bytes <= 0)
		return (NULL);
	map_buffer = calloc(sizeof(char), num_bytes);
	if (!map_buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	read(fd, map_buffer, num_bytes);
	close(fd);
	return (map_buffer);
}
