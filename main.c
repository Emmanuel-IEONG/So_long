/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:45 by eieong            #+#    #+#             */
/*   Updated: 2025/02/25 15:44:09 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *name)
{
	name = name + (ft_strlen(name) - 4);
	if (ft_strncmp(name, ".ber", 4))
	{
		perror("Wrong file extension");
		exit(1);
	}
	/*test open*/
}
int	main(int argc, char **argv)
{
	t_game	game;

	errno = 0;
	if (argc != 2)
	{
		perror("Number of arguments");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	/*check ".ber" in argv[1]*/
	check_filename(argv[1]);
	/*.ber valid ?*/
	game->fd = open(argv[1], O_RDONLY);
	/*check_map.c*/
	/*mlx init*/
}
