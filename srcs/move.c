/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:49 by ihama             #+#    #+#             */
/*   Updated: 2023/08/01 17:21:18 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	if (game->grid[game->imag->player->instances->y / 32 - 1]
		[game->imag->player->instances->x / 32] != '1')
	{
		game->imag->player->instances->y -= 32;
		game->move_count++;
		printf("move_up:%d\n", game->move_count);
	}
}

void	move_down(t_game *game)
{
	if (game->grid[game->imag->player->instances->y / 32 + 1]
		[game->imag->player->instances->x / 32] != '1')
	{
		game->imag->player->instances->y += 32;
		game->move_count++;
		printf("move_down:%d\n", game->move_count);
	}
}

void	move_left(t_game *game)
{
	if (game->grid[game->imag->player->instances->y / 32]
		[game->imag->player->instances->x / 32 - 1] != '1')
	{
		game->imag->player->instances->x -= 32;
		game->move_count++;
		printf("move_left:%d\n", game->move_count);
	}
}

void	move_right(t_game *game)
{
	if (game->grid[game->imag->player->instances->y / 32]
		[game->imag->player->instances->x / 32 + 1] != '1')
	{
		game->imag->player->instances->x += 32;
		game->move_count++;
		printf("move_right:%d\n", game->move_count);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE))
		mlx_close_window(game->mlx);
	collect_rupee(game);
}
