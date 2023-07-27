/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:35:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/27 19:54:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_image(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_game));
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->player = mlx_texture_to_image(game->mlx, game->textu->player);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->imag->wall);
	mlx_delete_texture(game->imag->floor);
	mlx_delete_texture(game->imag->player);
	mlx_delete_texture(game->imag->collec);
	mlx_delete_texture(game->imag->exit);
	mlx_delete_texture(game->imag->exit_2);
}

void	get_texture(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->wall = mlx_load_png("./textures/wall.png");
	game->textu->floor = mlx_load_png("./textures/floor.png");
	game->textu->player = mlx_load_png("./textures/Mago.png");
	game->textu->collec = mlx_load_png("./textures/spark21.png");
	game->textu->exit = mlx_load_png("./textures/salida.png");
	game->textu->exit_2 = mlx_load_png("./textures/salida2.png");
}

void	put_img_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[x][y])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->grid[x][y] == '1')
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			else if (game->grid[x][y] == 'E')
			{
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
				mlx_image_to_window(game->mlx, image->exit_2, x * 32, y * 32);
			}
		}
		x++;
	}
	y++;
}

void	put_img_map(t_game *game, t_game *image)
{
	int	x;
	int	y;

	put_img_floor(game, image);
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[x][y])
		{
			if (game->grid[x][y] == 'C')
				mlx_image_to_window(game->mlx, image->collect, x * 32, y * 32);
			if (game->grid[x][y] == 'P')
				mlx_image_to_window(game->mlx, image->player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
