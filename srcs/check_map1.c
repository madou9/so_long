/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:55:38 by ihama             #+#    #+#             */
/*   Updated: 2023/07/22 17:13:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_empty_line(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
			display_error("Error: empty line", true);
		i++;
	}
}

int	check_ber(char *map_file)
{
	char	*file_extension;
	int		i;

	file_extension = ".ber";
	i = 0;
	while (ft_strlen(map_file) != 4 && map_file)
		map_file++;
	if (!map_file || !*map_file)
		return (0);
	while (map_file[i])
	{
		if (map_file[i] != file_extension[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_wall(t_game *game)
{
	size_t	i;
	size_t	last_row;
	size_t	last_col;

	i = 0;
	last_row = game->height - 1;
	/* check the top and bottom rows */
	while (i < game->width)
	{
		if (game->grid[0][1] != '1' || game->grid[last_row][i] != '1')
			display_error("Error: the map is not surrounded by walls", true);
		i++;
	}
	/* Check the left and right columns (skip the top and bottom rows */
	i = 1;
	last_col = game->width - 1;
	while (i < last_row)
	{
		if (game->grid[i][0] != '1' || game->grid[i][last_col] != '1')
			display_error("Error: thr map is not surrounded by walls", true);
		i++;
	}
}
