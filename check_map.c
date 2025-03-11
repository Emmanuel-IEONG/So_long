/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:20:31 by eieong            #+#    #+#             */
/*   Updated: 2025/03/11 15:55:02 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*map rectangular = OK
	Same width everywhere = OK
	First and last line == '1' = OK
check walls around map* = OK
	check sides -> [0] & [width] = OK*/

t_bool	check_walls(t_game *game, int x, int y)
{
	while (y < game->height)
	{
		x = 0;
		// if (game->map[y][game->width] != '\n' && game->map[y][game->width])
		// 	return (ft_printf("Map must be a rectangle"), false);
		if (y == 0 || y == (game->height - 1))
		{
			while (game->map[y][x] && game->map[y][x] != '\n')
			{
				if (game->map[y][x] != '1')
					return (ft_printf("1: Map must be surrouded by walls\n"), ft_printf("y = %d, x = %d\n", y, x), false);
				x++;
			}
			if (x != game->width)
				return (ft_printf("width = %d\n", game->width), ft_printf("1: Map must be a rectangle\n"), false);
		}
		else
		{
			while (game->map[y][x])
				x++;
			if ((x - 1) != game->width)
				return (ft_printf("2: Map must be a rectangle\n"), false);
			if (game->map[y][0] != '1' || game->map[y][x - 2] != '1')
				return (ft_printf("2: Map must be surrouded by walls\n"), ft_printf("game->map[y][0] = %c, game->map[y][game->width - 1] = %c, game->map[y][x - 2] = %c\n",game->map[y][0], game->map[y][game->width - 1], game->map[y][x-2]), false);
			ft_printf("x = %d\n", x);
		}
		y++;
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
	{
		perror("malloc failed");
		return (false);
	}
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
		return (ft_printf("Map empty\n"), false);
	game->height++;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		game->width = line_len - 1;
	else
	{
		free(line);
		return (ft_printf("Invalid map\n"), false);
	}
	if (!line_to_map(game, line))
		return (free(line), false);
	while (1)
	{	
		line = get_next_line(game->fd);
		if (!line)
		{
			ft_printf("\nBREAK\n");
			break ;
		}
		game->height++;
		if (!line_to_map(game, line))
			return (free(line), false);
	}
	return (free(line), true);
}

t_bool	check_filename(char *name)
{
	if (ft_strlen(name) < 5)
	{
		ft_printf("Invalid file name\n");
		return (false);
	}
	name = name + (ft_strlen(name) - 4);
	if (ft_strncmp(name, ".ber", 4))
	{
		ft_printf("Wrong file extension\n");
		return (false);
	}
	return (true);
}
