/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:15:22 by ihama             #+#    #+#             */
/*   Updated: 2023/07/31 22:35:41 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	row_count(char **grid)
{
	int	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

int	count_rupees(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
			{
				i++;
			}
			x++;
		}
		y++;
	}
	return (i);
}

void delete_orbs(t_game *game, int y, int x)
{
	int i = 0;

	while (i < game->collect)
	{
		if (game->imag->collec->instances[i].y == y * game->img_size &&
			game->imag->collec->instances[i].x == x * game->img_size &&
			game->imag->collec->instances[i].enabled == true)
		{
			game->collect++;
			game->imag->collec->instances[i].enabled = false; // Disable the orb
			return;
		}
		i++;
	}
}

// Function to handle orb collection logic when the player moves
void	collect_rupee(t_game *game)
{
	int	player_y;
	int	player_x;

	player_x = game->imag->player->instances->x / 32;
	player_y = game->imag->player->instances->y / 32;
	if (game->grid[player_y][player_x] == 'C')
	{
		delete_orbs(game, player_y, player_x);
		game->grid[player_y][player_x] = '0';
		game->collect++;
		if (game->collect == 0)
			game->imag->exit->instances->enabled = false;
	}
	if (game->grid[player_y][player_x] == 'E')
	{
		printf("player : player_y : %d player_x: %d\n", player_y, player_x);
		// Check if all orbs are collected, and if yes, close the window
		printf("nomber of collect %d\n", game->collect);
		if (game->collect == 0)
			mlx_close_window(game->mlx);
	}
}
