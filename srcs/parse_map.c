/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:15:44 by ihama             #+#    #+#             */
/*   Updated: 2023/07/22 19:02:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	flood_fill(t_game *map, t_game curr, char **grid)
{
	int		piece;
	bool	found_exit;

	found_exit = false;
	piece = 0;
	if (grid[curr.y][curr.x] == WALL)
		return (false);
	else if (grid[curr.y][curr.x] == COLLECTIBLE)
		piece += 1;
	else if (grid[curr.y][curr.x] == EXIT)
		found_exit = true;
	grid[curr.y][curr.x] = WALL;
	flood_fill(map, (t_game){curr.x - 1, curr.y}, grid);
	flood_fill(map, (t_game){curr.x + 1, curr.y}, grid);
	flood_fill(map, (t_game){curr.x, curr.y - 1}, grid);
	flood_fill(map, (t_game){curr.x, curr.y + 1}, grid);
	return (piece == map->coins && found_exit);
}

void	free_grid(t_game **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	check_path(t_game *map)
{
	t_game	tmp;
	size_t	i;

	i = 0;
	/* Copies important game properties into a temporary structure.*/
	tmp.height = map->height;
	tmp.width = map->width;
	tmp.coins = map->coins;
	tmp.x = map->x;
	tmp.y = map->y;
	tmp.exit_x = 0;
	tmp.exit_y = 0;
	tmp.grid = ((char **)malloc(sizeof(char *) * tmp.height));
	if (!tmp.grid)
		return (NULL);
	/* Copy each line of the game grid into the temporary copy */
	while (i < tmp.height)
	{
		tmp.grid[i] = ft_strdup(map->grid[i]);
		i++;
	}
	/*Checks path validity by calling the check_path function*/
	if (!flood_fill(map, (t_game){tmp.x, tmp.y}, tmp.grid))
		display_error("no path valid", true);
	free_grip(tmp.grid, tmp.height);
}
