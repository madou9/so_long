/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/19 17:37:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

char	*read_map(char *str)
{
	int		fd;
	char	*str_map;
	char	*line;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		display_error("Error opening the map file.\n", true);
	str_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str_map = ft_strjoin(str_map, line);
		free(line);
	}
	close(fd);
	map = ft_split(str_map, '\n');
	free(str_map);
	return (map);
}
