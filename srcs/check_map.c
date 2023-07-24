/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:26:25 by ihama             #+#    #+#             */
/*   Updated: 2023/07/24 15:06:04 by ihama            ###   ########.fr       */
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
		printf("put 01PEC in map");
}

void	check_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	if (!game->grid)
		free(game);
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
		printf("at least one collectible");
	if (game->player == 0)
		printf("at least one player");
	if (game->player > 1)
		printf("almost one player allowed");
	if (game->exit == 0 || game->exit > 1)
		printf("MIssing an exit or too many");
}

void	check_map_rectangle(char **map)
{
	size_t	first_row_len;
	size_t	i;

	i = 0;
	first_row_len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != first_row_len)
			printf("damm your map is not rectangle");
		i++;
	}
}

void	check_empty_map(char **map)
{
	if (map[0] == NULL)
		printf("dammm your map is empty");
}
