/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:45 by eieong            #+#    #+#             */
/*   Updated: 2025/03/06 12:33:14 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
int	main(int argc, char **argv)
{
	t_game	*game;

	errno = 0;
	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"), 1);
	if (!check_filename(argv[1]))
		return (1);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (ft_printf("Invalid file\n"), 1);
	if (!get_map(game))
		return (1);
	if (!check_walls(game, 0, 0))
		return (1);
	if (!is_map_valid(game))
		return (1);
	/*mlx init*/
}
