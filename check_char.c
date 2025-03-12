/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/03/12 16:37:56 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_pos pos, t_game *game)
{
	if (map[pos.y][pos.x] == '1' || pos.y < 0 || pos.x < 0
			|| pos.x > game->width || pos.y > game->height)
		return ;
	if (map[pos.y][pos.x] == 'C')
		game->c_count--;
	if (map[pos.y][pos.x] == 'E')
	{
		game->e_count--;
		map[pos.y][pos.x] = '1';
		return ;
	}
	map[pos.y][pos.x] = '1';
	flood_fill(map, (t_pos){pos.x - 1, pos.y}, game);
	flood_fill(map, (t_pos){pos.x + 1, pos.y}, game);
	flood_fill(map, (t_pos){pos.x, pos.y + 1}, game);
	flood_fill(map, (t_pos){pos.x, pos.y - 1}, game);
}

char	**dup_map(t_game *game)
{
	char	**mapcopy;
	int		i;

	i = 0;
	mapcopy = malloc(sizeof(char *) * (game->height + 1));
	if (!mapcopy)
		return (NULL);
	while (i < game->height)
	{
		mapcopy[i] = ft_strdup(game->map[i]);
		i++;
	}
	mapcopy[i] = NULL;
	return (mapcopy);
}

t_bool	char_count(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->c_count++;
	else if (game->map[y][x] == 'E')
		game->e_count++;
	else if (game->map[y][x] == 'P')
	{
		game->p_count++;
		game->pos.x = x;
		game->pos.y = y;
	}
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
		return (ft_printf("Unauthorized char"), false);
	return (true);
}

t_bool	check_char(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width - 1)
		{
			if (!char_count(game, x, y))
				return (false);
		}
	}
	if (game->c_count < 1)
		ft_printf("At least 1 collectible needed\n");
	if (game->e_count != 1)
		ft_printf("Wrong number of exit\n");
	if (game->p_count != 1)
		ft_printf("Wrong number of player\n");
	if (game->c_count < 1 || game->e_count != 1 || game->p_count != 1)
		return (false);
	return (true);
}

t_bool	is_map_valid(t_game *game)
{
	char	**mapcopy;
	int		temp_c_count;
	int		temp_e_count;

	if (!check_char(game))
		return (false);
	mapcopy = dup_map(game);
	if (!mapcopy)
		return (perror("malloc failed"), false);
	temp_c_count = game->c_count;
	temp_e_count = game->e_count;
	flood_fill(mapcopy, (t_pos){game->pos.x, game->pos.y}, game);
	ft_print_tab(mapcopy);
	if (game->c_count != 0 || game->e_count != 0)
		return (ft_printf("Can't reach C or E\n"), ft_freetab(mapcopy), false);
	game->c_count = temp_c_count;
	game->e_count = temp_e_count;
	return (ft_freetab(mapcopy), true);
}
