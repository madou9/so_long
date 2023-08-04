/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:26:25 by ihama             #+#    #+#             */
/*   Updated: 2023/08/04 15:46:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_and_count_characters(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->collect++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->link_y = y;
		game->link_x = x;
	}
	else if (c != '1' && c != '0')
		error_message("Invalid character found in the map");
}

void	check_contents_map(t_game *game)
{
	int	x;
	int	y;

	game->collect = 0;
	game->exit = 0;
	game->player = 0;
	x = 0;
	while (game->grid[x])
	{
		y = 0;
		while (game->grid[x][y])
		{
			validate_and_count_characters(game, game->grid[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->collect == 0)
		error_message("At least one collectible (C) is required in the map");
	if (game->player == 0)
		error_message("At least one player (P) is required in the map");
	if (game->player > 1)
		error_message("Only one player (P) is allowed in the map");
	if (game->exit == 0 || game->exit > 1)
		error_message("Exactly one exit (E) is required in the map");
}

void	check_empty_line(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
		{
			error_message("Error: Map contains empty lines");
		}
		i++;
	}
}

void	check_empty_map(char *map)
{
	size_t	i;

	i = 0;
	if (!map[i])
		error_message("Map is empty");
}
