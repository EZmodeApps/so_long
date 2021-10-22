/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/22 19:41:00 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define BUFFER_SIZE 1
# define SUCCESS 0
# define ERROR 1
# define PLAYER_1 "./textures/player_new.xpm"
# define WALL "./textures/new_wall.xpm"
# define FLOOR "./textures/new_floor.xpm"
# define EXIT "./textures/exit.xpm"
# define COLLECTIBLE "./textures/coin.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_main
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	int			size_x;
	int			size_y;
	int			collectibles;
	int			num_of_players;
	int			exit;
	int			moves;
	t_player	*player;
}				t_main;

size_t	strlen_gnl(char *s);
char	*strjoin_gnl(char *saved_buf, char *buf);
int		get_next_line(int fd, char **line);
char	*clear_saved_buf(char *saved_buf);
char	*get_line(char *saved_buf);

#endif
