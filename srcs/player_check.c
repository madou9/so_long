/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:37:51 by ihama             #+#    #+#             */
/*   Updated: 2023/07/24 17:15:28 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_game *game, int x, int y)
{
	if (game->mapcopy[x][y] == 'P' &&
	(game->mapcopy[x][y + 1] == 'C'
	|| game->mapcopy[x][y + 1] == '0'
	|| game->mapcopy[x - 1][y] == 'C'
	|| game->mapcopy[x - 1][y] == '0'
	|| game->mapcopy[x][y - 1] == 'C'
	|| game->mapcopy[x][y - 1] == '0'
	|| game->mapcopy[x + 1][y] == 'C'
	|| game->mapcopy[x + 1][y] == '0'))
		return (1);
	return (0);
}

void	aroundplayer(t_game *game, int x, int y)
{
	if (game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0')
	{
		if (game->mapcopy[x][y] == 'C')
			game->copycollect--;
		game->mapcopy[x][y] = 'P';
	}
}

int	mapcopy(t_game *game)
{
	int	x;
	int	y;

	game->mapcopy = ft_calloc(game->link_y + 1, sizeof(char *));
	if (!game->mapcopy)
		return (0);
	while (game->grid[x])
	{
		game->mapcopy[x] = ft_calloc(game->link_x + 1, sizeof(char));
		if (!game->mapcopy[x])
			return (0);
		y = 0;
		while (game->grid[x][y])
		{
			game->mapcopy[x][y] = game->grid[x][y];
			y++;
		}
		x++;
	}
	game->mapcopy[x] = NULL;
	return (1);
}

int	path_ok(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->copycollect = game->collect;
	while (x < game->link_y)
	{
		y = 0;
		while (game->mapcopy[x][y])
		{
			if (checkplayer(game, x, y))
			{
				aroundplayer(game, x + 1, y);
				aroundplayer(game, x - 1, y);
				aroundplayer(game, x, y + 1);
				aroundplayer(game, x, y - 1);
				x = 0;
			}
			y++;
		}
		x++;
	}
	if (game->copycollect == 0 && exitcheck(game))
		return (1);
	printf("no path found");
}
