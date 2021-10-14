//
// Created by EZmodeApps on 10.10.2021.
//

#ifndef SO_LONG_SO_LONG_H
#define SO_LONG_SO_LONG_H

#define BUFFER_SIZE 1

#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_player
{
	int x;
	int y;
}				t_player;

typedef struct	s_main
{
	t_player *player;
	char *map;
	int size_x;
	int size_y;
}				t_main;

size_t	strlen_gnl(char *s);
char	*strjoin_gnl(char *saved_buf, char *buf);
int		get_next_line(int fd, char **line);
char	*clear_saved_buf(char *saved_buf);
char	*get_line(char *saved_buf);


#endif //SO_LONG_SO_LONG_H
