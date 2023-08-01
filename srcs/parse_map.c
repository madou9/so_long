/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:15:44 by ihama             #+#    #+#             */
/*   Updated: 2023/08/01 15:26:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	*start_pos(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_map(t_game *game, int y, int x)
{
	get_width_and_height(game);
	if (!(x < 1 || y < 1 || x >= game->width || y >= game->height
			|| game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == 'X'))
	{
		game->mapcopy[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

int	check_flood(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->mapcopy[y])
	{
		x = 0;
		while (game->mapcopy[y][x])
		{
			if (!(game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == '0'
				|| game->mapcopy[y][x] == 'X'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	valid_path(t_game *game, char *fd)
{
	int		*pos;
	char	**map_as_array;
	char	*map_as_str;

	map_as_str = read_map_file(fd);
	map_as_array = ft_split(map_as_str, '\n');
	game->mapcopy = map_as_array;
	pos = start_pos(game->mapcopy);
	flood_map(game, pos[0], pos[1]);
	free(pos);
	if (check_flood(game) == 1)
	{
		free_map(game->mapcopy);
		error_message("There is no valid path.");
	}
	free_map(game->mapcopy);
	return (0);
}
