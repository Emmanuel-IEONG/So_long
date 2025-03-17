/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:20:31 by eieong            #+#    #+#             */
/*   Updated: 2025/03/17 16:13:16 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bool	check_walls(t_game *game, int x, int y)
{
	while (++y < game->height)
	{
		x = 0;
		if (y == 0 || y == (game->height - 1))
		{
			while (game->map[y][x] && game->map[y][x] != '\n')
			{
				if (game->map[y][x] != '1')
					return (err_msg(6), false);
				x++;
			}
			if (x != game->width)
				return (err_msg(7), false);
		}
		else
		{
			while (game->map[y][x])
				x++;
			if ((x - 1) != game->width)
				return (err_msg(7), false);
			if (game->map[y][0] != '1' || game->map[y][x - 2] != '1')
				return (err_msg(6), false);
		}
	}
	return (true);
}

t_bool	check_map_size(t_game *game)
{
	if (game->width > 30 || game->height > 16)
	{
		ft_printf("Error\nMap is too big.\n");
		return (false);
	}
	return (true);
}

t_bool	line_to_map(t_game *game, char *line)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char *) * (game->height + 1));
	if (!temp)
		return (perror ("Error"), false);
	temp[game->height] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (true);
}

t_bool	get_map(t_game *game)
{
	char	*line;
	int		line_len;

	line_len = 0;
	line = get_next_line(game->fd);
	if (!line)
		return (err_msg(4), false);
	game->height++;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		game->width = line_len - 1;
	else
		return (free(line), err_msg(5), false);
	while (line)
	{	
		if (!line_to_map(game, line))
			return (free(line), false);
		line = get_next_line(game->fd);
		game->height++;
	}
	game->height--;
	if (!check_map_size(game))
		return (free(line), false);
	return (free(line), true);
}

t_bool	check_filename(char *name)
{
	if (ft_strlen(name) < 5)
	{
		err_msg(2);
		return (false);
	}
	name = name + (ft_strlen(name) - 4);
	if (ft_strncmp(name, ".ber", 4))
	{
		err_msg(3);
		return (false);
	}
	return (true);
}
