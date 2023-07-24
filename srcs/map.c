/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 21:20:37 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*read_map(const char *str)
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
	return (*map);
}

void	display_error(const char *error_msg, bool exit_program)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (exit_program)
		exit(EXIT_FAILURE);
}
