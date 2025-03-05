/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/03/05 11:56:13 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*only 1E, 1P and mini 1C (&'1'/'0') and nothing else = OK*/

/*E accessible from P ? flood fill algo*/
/*C accessible from P ?*/
/*flood fill algo : recursive
ft_fill */

void	flood_fill(char **map, t_pos pos, t_game *game)
{
	if (map[pos.x][pos.y] == '1' || pos.x < 0 || pos.y < 0
			|| pos.x > game->width || pos.y > game->height)
		return ;
	if (map[pos.x][pos.y] == 'C')
		game->c_count--;
	if (map[pos.x][pos.y] == 'E')
		game->e_count--;
	map[pos.x][pos.y] = '1';
	flood_fill(map, (t_pos){pos.x, pos.y - 1}, game);
	flood_fill(map, (t_pos){pos.x, pos.y + 1}, game);
	flood_fill(map, (t_pos){pos.x + 1, pos.y}, game);
	flood_fill(map, (t_pos){pos.x - 1, pos.y}, game);
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

void	char_count(t_game *game, int x, int y)
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
		perror("Unauthorized char");
}

void	check_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			char_count(game, x, y);
			x++;
		}
		y++;
	}
	if (game->c_count < 1)
		perror("At least 1 collectible needed");
	if (game->e_count != 1)
		perror("Wrong number of exit");
	if (game->p_count != 1)
		perror("Wrong number of player");
}

t_bool	is_map_valid(t_game *game)
{
	char	**mapcopy;
	int		temp_c_count;
	int		temp_e_count;

	check_char(game);
	mapcopy = dup_map(game);
	temp_c_count = game->c_count;
	temp_e_count = game->e_count;
	flood_fill(mapcopy, (t_pos){game->pos.x, game->pos.y}, game);
	/*check C, E, P = 0*/
	if (game->c_count != 0 || game->e_count != 0)
		return (false);
	game->c_count = temp_c_count;
	game->e_count = temp_e_count;
	return (true);
}
