/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:15:22 by ihama             #+#    #+#             */
/*   Updated: 2023/08/01 17:19:01 by ihama            ###   ########.fr       */
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

void	delete_orbs(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->collect)
	{
		if (game->imag->collec->instances[i].y == y * game->img_size)
		{
			if (game->imag->collec->instances[i].x == x * game->img_size)
			{
				if (game->imag->collec->instances[i].enabled == true)
				{
					game->imag->collec->instances[i].enabled = false;
					return ;
				}
			}
		}
		i++;
	}
}

void	collect_rupee(t_game *game)
{
	int	player_y;
	int	player_x;

	player_y = game->imag->player->instances->y / 32;
	player_x = game->imag->player->instances->x / 32;
	if (game->grid[player_y][player_x] == 'C')
	{
		delete_orbs(game, player_y, player_x);
		game->grid[player_y][player_x] = '0';
		game->collect--;
		if (game->collect == 0)
			game->imag->exit->instances->enabled = false;
			if (mlx_image_to_window(game->mlx, game->imag->exit_2,
				game->img_size, game->img_size) < 0)
			error_message("Failed to put image to window");
	}
	if (game->grid[player_y][player_x] == 'E')
	{
		if (game->collect == 0)
			mlx_close_window(game->mlx);
	}
}
