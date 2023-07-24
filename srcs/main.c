/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:12:26 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 22:19:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc == 2)
	{
		// map = read_map(argv[1]);
		// check_content_map(map);
		initilize_data(&argv[1]);

	}
	write(1, "Error: at least 2 files\n", 1);
}
