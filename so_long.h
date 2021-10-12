//
// Created by Ilya on 10.10.2021.
//

#ifndef SO_LONG_SO_LONG_H
#define SO_LONG_SO_LONG_H

#define BUFFER_SIZE 1

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_map
{
	char **map;
	int size;
}				t_map;

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *saved_buf, char *buf);
int		get_next_line(int fd, char **line);
char	*clear_saved_buf(char *saved_buf);
char	*get_line(char *saved_buf);

#define PATH_TO_FILE /Users/ez_mode/Developer/GitHub/so_long/map.ber

#endif //SO_LONG_SO_LONG_H
