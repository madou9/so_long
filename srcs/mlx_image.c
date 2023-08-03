/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:35:29 by ihama             #+#    #+#             */
/*   Updated: 2023/08/03 14:48:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_image(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images));
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->player = mlx_texture_to_image(game->mlx, game->textu->player);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->player);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
}

void	get_texture(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->wall = mlx_load_png("textures/wall.png");
	game->textu->floor = mlx_load_png("textures/Grass.png");
	game->textu->player = mlx_load_png("textures/zenitsu.png");
	game->textu->collec = mlx_load_png("textures/spark.png");
	game->textu->exit = mlx_load_png("textures/exit.png");
	game->textu->exit_2 = mlx_load_png("textures/exit_2.png");
}

void	resize_image(t_game *game)
{
	mlx_resize_image(game->imag->floor, game->img_size, game->img_size);
	mlx_resize_image(game->imag->wall, game->img_size, game->img_size);
	mlx_resize_image(game->imag->player, game->img_size, game->img_size);
	mlx_resize_image(game->imag->collec, game->img_size, game->img_size);
	mlx_resize_image(game->imag->exit, game->img_size, game->img_size);
	mlx_resize_image(game->imag->exit_2, game->img_size, game->img_size);
}

void	image_select(t_game *data, char val, size_t ay, size_t ax)
{
	if (val == '1')
		if (mlx_image_to_window(data->mlx, data->imag->wall,
				ax, ay) < 0)
			error_message("Failed to put image to window");
	if (val == 'C')
		if (mlx_image_to_window(data->mlx, data->imag->collec,
				ax, ay) < 0)
			error_message("Failed to put image to window");
	if (val == 'P')
		if (mlx_image_to_window(data->mlx, data->imag->player,
				ax, ay) < 0)
			error_message("Failed to put image to window");
	if (val == 'E')
	{
		mlx_image_to_window(data->mlx, data->imag->exit_2, ax, ay);
		mlx_image_to_window(data->mlx, data->imag->exit, ax, ay);
	}
}

void	fill_background(t_game *data)
{
	int		x;
	int		y;
	int		ax;
	int		ay;

	y = 0;
	ay = 0;
	while (y < data->height)
	{
		x = 0;
		ax = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->imag->floor,
					ax, ay) < 0)
				error_message("Failed to put image to window");
			x++;
			ax += data->img_size;
		}
		y++;
		ay += data->img_size;
	}
}
