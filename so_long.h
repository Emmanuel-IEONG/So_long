/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:30 by eieong            #+#    #+#             */
/*   Updated: 2025/03/05 14:25:10 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	char	**map;

	int		fd;
	int		width;
	int		height;
	// int		x_pos;
	// int		y_pos;
	t_pos	pos;
	int		collectibles_left;
	int		move_count;
	int		c_count;
	int		e_count;
	int		p_count;
	// int		c_floodfill;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*collectibles;
	void	*exit;
	void	*floor;
	void	*player;
	void	*wall_0;
	void	*wall_1;
}			t_game;

#endif
