/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:20:31 by eieong            #+#    #+#             */
/*   Updated: 2025/02/26 17:48:31 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*map rectangular = OK*/
	/*Same width everywhere = OK*/
	/*First and last line == '1' = OK*/
/*check walls around map* = OK/
	/*check sides -> [0] & [width] = OK*/

t_bool	check_walls(t_game *game, int index)
{
	int	i;

	i = 0;
	if (game->map[index][game->width])
		return (perror("Map must be a rectangle"), false);
	if (index == 0 || index == game->height)
	{
		while (game->map[index][i])
		{
			if (game->map[index][i] != '1')
				return (false);
			i++;
		}
		return (true);
	}
	else
	{
		if (game->map[index][0] != '1')
			return (false);
		if (game->map[index][game->width - 1] != '1')
			return (false);
		return (true);
	}
}

void	line_to_map(t_game *game, char *line)
{
	char	*temp;

	temp = ft_substr(line, 0, ft_strlen(line) - 1);
	game->map[game->height] = temp;
	free(temp);
	game->height++;
}

void	get_map(t_game *game)
{
	char	*line;
	int		line_len;

	line_len = 0;
	line = get_next_line(game->fd);
	if (!line)
	{
		perror("Map empty");
	}
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		game->width = line_len - 1;
	else
		perror("Invalid map");
	line_to_map(game, line);
	if (!check_walls(game, game->height - 1))
		perror("Map is not surrounded by walls");
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		line_to_map(game, line);
		if (!check_walls(game, game->height - 1))
			perror("Map is not surrounded by walls");
	}
	game->map[game->height] = NULL;
	if (!check_walls(game, game->height))
		perror("Map is not surrounded by walls");
}
