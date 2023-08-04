/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:29 by ihama             #+#    #+#             */
/*   Updated: 2023/08/04 16:20:06 by ihama            ###   ########.fr       */
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
	char	*temp;
	int		total_bytes;
	int		bit_chunk;
	int		fd;

	fd = open(map, O_RDONLY);
	total_bytes = 0;
	temp = malloc (sizeof(int) * 1024);
	if (fd == -1)
		error_message("can't find file");
	bit_chunk = read(fd, temp, 1024);
	if (!(bit_chunk))
	{
		free (temp);
		close(fd);
	}
	total_bytes = total_bytes + bit_chunk;
	if (bit_chunk != '\0')
	{
		bit_chunk = read(fd, temp, 1024);
		total_bytes = total_bytes + bit_chunk;
	}
	close(fd);
	free (temp);
	return (total_bytes);
}

char	*read_map_file(char *filename)
{
	int		fd;
	int		num_bytes;
	char	*map_buffer;

	num_bytes = get_map_size(filename) + 1;
	if (num_bytes <= 0)
		return (NULL);
	map_buffer = ft_calloc(sizeof(char), num_bytes);
	if (!map_buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	read(fd, map_buffer, num_bytes);
	close(fd);
	return (map_buffer);
}
