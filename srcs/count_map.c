/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:15:22 by ihama             #+#    #+#             */
/*   Updated: 2023/08/02 17:29:42 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	delete_orbs(t_game *game, int y, int x)
{
	int	orb_i;

	x = x * game->img_size;
	y = y * game->img_size;
	orb_i = 0;
	while (orb_i < game->collect_cpy)
	{
		if (game->imag->collec->instances[orb_i].x
			== x && game->imag->collec->instances[orb_i].y == y)
			game->imag->collec->instances[orb_i].enabled = false;
		orb_i++;
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
		printf("i took the collectibles\n");
		delete_orbs(game, player_y, player_x);
		game->grid[player_y][player_x] = '0';
		game->collect--;
		if (game->collect == 0)
			game->imag->exit->instances->enabled = false;
	}
	if (game->grid[player_y][player_x] == 'E' && game->collect == 0)
	{
		mlx_close_window(game->mlx);
		printf("Congratulations!\n");
		printf("You made link rich! 💰💰💰\n");
		printf("He can now sleep in his hole in the ground\n");
	}
}
