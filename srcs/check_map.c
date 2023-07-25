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
		error_message("put 01PEC in map");
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
		error_message("at least one collectible\n");
	if (game->player == 0)
		error_message("at least one player\n");
	if (game->player > 1)
		error_message("almost one player allowed\n");
	if (game->exit == 0 || game->exit > 1)
		error_message("MIssing an exit or too many\n");
}

int	check_shape(char *map)
{
	char	**map_sketch;
	size_t	reference;
	int		i;
	int		j;

	map_sketch = ft_split(map, '\n');
	reference = ft_strlen(map_sketch[0]);
	i = count_line(map_sketch);
	j = 0;
	while (j < i)
	{
		if (ft_strlen(map_sketch[j]) != reference)
		{
			printf("Error :check shape\n");
			free_string_array(map_sketch);
			return (TRUE);
		}
		j++;
	}
	printf("Good:check shape\n");
	free_string_array(map_sketch);
	return (0);
}

void	check_empty(char *map)
{
	size_t	i;

	i = 0;
	if (!map[i])
		error_message("Map is empty");
}
