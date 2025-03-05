/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:20:31 by eieong            #+#    #+#             */
/*   Updated: 2025/03/05 15:59:47 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*map rectangular = OK*/
	/*Same width everywhere = OK*/
	/*First and last line == '1' = OK*/
/*check walls around map* = OK/
	/*check sides -> [0] & [width] = OK*/

t_bool	check_walls(t_game *game, int x, int y)
{
	while (y <= game->height)
	{
		x = 0;
		if (game->map[y][game->width])
			return (ft_printf("Map must be a rectangle"), false);
		if (y == 0 || y == game->height)
		{
			while (game->map[y][x])
			{
				if (game->map[y][x] != '1')
					return (false);
				x++;
			}
		}
		else
		{
			if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
				return (false);
		}
		y++;
	}
	return (true);
}

void	line_to_map(t_game *game, char *line)
{
	char	*temp;

	temp = ft_substr(line, 0, ft_strlen(line) - 1);
	game->map[game->height] = temp;
	free(temp);
	game->height++;
}
t_bool	get_map(t_game *game)
{
	char	*line;
	int		line_len;

	line_len = 0;
	line = get_next_line(game->fd);
	if (!line)
		return (ft_printf("Map empty"), false);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		game->width = line_len - 1;
	else
	{
		free(line);
		return (ft_printf("Invalid map"), false);
	}
	line_to_map(game, line);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		line_to_map(game, line);
	}
	game->map[game->height] = NULL;
	return (free(line), true);
}

// void	get_map(t_game *game)
// {
// 	char	*line;
// 	int		line_len;

// 	line_len = 0;
// 	line = get_next_line(game->fd);
// 	if (!line)
// 		perror("Map empty");
// 	line_len = ft_strlen(line);
// 	if (line[line_len - 1] == '\n')
// 		game->width = line_len - 1;
// 	else
// 		perror("Invalid map");
// 	line_to_map(game, line);
// 	if (!check_walls(game, game->height - 1))
// 		perror("Map is not surrounded by walls");
// 	while (1)
// 	{
// 		line = get_next_line(game->fd);
// 		if (!line)
// 			break ;
// 		line_to_map(game, line);
// 		if (!check_walls(game, game->height - 1))
// 			perror("Map is not surrounded by walls");
// 	}
// 	game->map[game->height] = NULL;
// 	if (!check_walls(game, game->height))
// 		perror("Map is not surrounded by walls");
// }
