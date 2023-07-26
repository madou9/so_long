t_game *initialize_game_struct(char **grid)
{
	t_game	*game_data; // Change variable name to avoid naming conflict

	game_data = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game_data)
		error_message("struct memory allocation failed");
	game_data->width = ft_strlen(grid[0]); // Use game_data instead of game
	game_data->height = row_count(grid); // Use game_data instead of game
	game_data->grid = grid; // Use game_data instead of game
	game_data->collect = count_rupees(game_data); // Use game_data instead of game
	game_data->link_x = get_link_pos(game_data, 'x'); // Use game_data instead of game
	game_data->link_y = get_link_pos(game_data, 'y'); // Use game_data instead of game
	game_data->exit = get_exit_pos(game_data, 'x'); // Use game_data instead of game
	game_data->exit_y = get_exit_pos(game_data, 'y'); // Use game_data instead of game
	return (game_data); // Use game_data instead of game
}

// t_game	*initialize_data(char *map)
// {
// 	char	*map_as_str;
// 	char	**map_as_array;
// 	t_game	*data;

// 	map_as_str = read_map(map);
// 	check_empty(map_as_str);
// 	check_empty_lines(map_as_str);
// 	check_map_content(map_as_str);
// 	map_as_array = ft_split(map_as_str, '\n');
// 	check_map_shape(map_as_array);
// 	data = initialize_game_struct(map_as_array);
// 	check_walls(data);
// 	flood_fill(data);
// 	free (map_as_str);
// 	return (data);
// }


void	check_map(t_game *game);
int		get_map_size(char *map);
int		exitcheck(t_game *game);
int		checkplayer(t_game *game, int x, int y);
char	*read_map_file(char *filename);
void	check_empty(char *map);
void	check_path(t_game *game);
void	free_grid(char **grid, size_t height);

/* initialisation */
t_game *initialize_game_struct(char **grid);
int		count_line(char **xy_map);
void	free_string_array(char **array);
int		check_shape(char *map);
void	check_map(t_game *game);
void	aroundplayer(t_game *game, int x, int y);
void	validate_and_count_characters(t_game *game, char c, int x, int y);
void	error_message(char *msg);
void	check_walls(t_game *game);

/* */
int	row_count(char **grid);
int	count_rupees(t_game *game);
int	get_link_pos(t_game *game, char c );
int	get_exit_pos(t_game *game, char c );