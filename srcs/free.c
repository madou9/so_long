int	checkplayer(t_game *game, int x, int y)
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

int	exitcheck(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->mapcopy[x])
	{
		y = 0;
		while (game->mapcopy[x][y])
		{
			if ((game->mapcopy[x][y] == 'E' && game->mapcopy[x][y + 1] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x][y - 1] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x - 1][y] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x + 1][y] == 'P'))
				return (1);
			y++;
		}
		x++;
	}
	error_message("\033[0;31mNo succesfull path found\n\e[0m");
	return 0;
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
	error_message("\033[0;31mNo succesfull path found\n\e[0m");
	return 0;
}