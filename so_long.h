/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 19:47:36 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define SUCCESS 0
# define ERROR 1
# define PLAYER "./textures/player.xpm"
# define WALL "./textures/wall.xpm"
# define FLOOR "./textures/floor.xpm"
# define EXIT "./textures/exit.xpm"
# define COLLECTIBLE "./textures/collectible.xpm"
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
	void		*picWall;
	void		*picFloor;
	void		*picExit;
	void		*picCollectible;
	int			pic_width;
	int			pic_height;
	t_player	*player;
}				t_main;

size_t	strlen_gnl(char *s);
char	*strjoin_gnl(char *saved_buf, char *buf);
int		get_next_line(int fd, char **line);
char	*clear_saved_buf(char *saved_buf);
char	*get_line(char *saved_buf);
void	mapDataInit2(t_main *mapData);
t_main	*mapDataInit(void);
void	freeMap(t_main *mapData);
void	structFree(t_main *mapData);
int		drawFloor(t_main *mapData, int x, int y);
int		drawWall(t_main *mapData, int x, int y);
int		drawExit(t_main *mapData, int x, int y);
int		drawCollectibles(t_main *mapData, int x, int y);
void	drawMap(t_main *mapData);
void	drawPlayer(t_main *mapData);
int		getMapHeight(char *mapInput);
int		getMapWidth(char *mapInput);
void	locatePlayer(t_main *mapData);
void	countCollectibles(t_main *mapData);
void	countExit(t_main *mapData);
void	W_is_pressed(t_main *mapData);
void	S_is_pressed(t_main *mapData);
void	D_is_pressed(t_main *mapData);
void	A_is_pressed(t_main *mapData);
int		key_hook(int keycode, t_main *mapData);
int		render_next_frame(t_main *mapData);
int		checkExtension(char *filename);
int		checkMapSymbols(t_main *mapData);
int		checkMapSize(t_main *mapData);
int		checkWalls(t_main *mapData);
void	handleErrors(int argc, char *filename);
void	fillMapData(t_main *mapData, char *map);
void	getMap(t_main *mapData, char *map);
void	checkMap2(t_main *mapData);
void	checkMap(t_main *mapData);

#endif
