/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:33:12 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_exit(t_main *mapData) //сюда универсальный free
{
	exit (0);
}

t_main *structInit(void)
{
	t_main *mapData;

	mapData = malloc(sizeof(t_main));
	mapData->map = NULL;
	mapData->player = (t_player *)malloc(sizeof(t_player));
	mapData->player->x = 0;
	mapData->player->y = 0;
	mapData->width = 0;
	mapData->height = 0;
	mapData->moves = 0;
	return (mapData);
}

void structFree(t_main *mapData)
{
	mapData->map = NULL;
	mapData->mlx = NULL;
	mapData->mlx_win = NULL;
	mapData->width = 0;
	mapData->height = 0;
	free(mapData->player);
	mapData->player->x = 0;
	mapData->player->y = 0;
	free(mapData);
}

void drawMap(t_main *mapData)
{
	int i;
	int x;
	int y;
	int j;
	void	*picWall;
	void *picFloor;
	void *picExit;
	void *picCollectible;
	int pic_width;
	int pic_height;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	picWall = mlx_xpm_file_to_image(mapData->mlx, WALL, &pic_width, &pic_height);
	picFloor = mlx_xpm_file_to_image(mapData->mlx, FLOOR, &pic_width, &pic_height);
	picExit = mlx_xpm_file_to_image(mapData->mlx, EXIT, &pic_width, &pic_height);
	picCollectible = mlx_xpm_file_to_image(mapData->mlx, COLLECTIBLE, &pic_width, &pic_height);
	while (mapData->map[j])
	{
		//printf("j = %d\n", j);
		i = 0;
		x = 0;
		while (mapData->map[j][i])
		{
			//printf("i = %d\n", i);
			if (mapData->map[j][i] == 'P' || mapData->map[j][i] == '0')
			{
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picFloor, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == '1') {
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picWall, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == 'E') {
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picExit, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == 'C') {
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picCollectible, x, y);
				x += 32;
			}
			i++;
		}
		j++;
		y += 32;
	}
}

void putPlayer(t_main *mapData)
{
	int pic_width;
	int pic_height;
	void *picPlayer;

	picPlayer= mlx_xpm_file_to_image(mapData->mlx, PLAYER_1, &pic_width, &pic_height);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picPlayer, mapData->player->x * 32, mapData->player->y * 32);
}

int getMapHeight(char *mapInput)
{
	int n;
	int fd;
	int counter;
	char *line;

	n = 1;
	counter = 0;
	fd = open(mapInput, O_RDONLY);
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		counter++;
		free (line);
	}
	return (counter);
}

int getMapWidth(char *mapInput)
{
	int length;
	int fd;
	char *line;

	length = 0;
	fd = open(mapInput, O_RDONLY);
	get_next_line(fd, &line);
	length = (int)ft_strlen(line);
	free (line);
	return (length);
}

void locatePlayer(t_main *mapData)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == 'P')
			{
				mapData->player->x = j;
				mapData->player->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	key_hook(int keycode, t_main *mapData)
{
	if (keycode == ESC)
	{
		mlx_clear_window(mapData->mlx, mapData->mlx_win);
		mlx_destroy_window(mapData->mlx, mapData->mlx_win);
		//free
		exit(SUCCESS);
	}
	if (keycode == W)
		if (mapData->map[mapData->player->y - 1][mapData->player->x] != '1')
			mapData->player->y -= 1;
	if (keycode == S)
		if (mapData->map[mapData->player->y + 1][mapData->player->x] != '1')
			mapData->player->y += 1;
	if (keycode == D)
		if (mapData->map[mapData->player->y][mapData->player->x + 1] != '1')
			mapData->player->x += 1;
	if (keycode == A)
		if (mapData->map[mapData->player->y][mapData->player->x - 1] != '1')
			mapData->player->x -= 1;
	printf("%d\n", keycode);
}

int render_next_frame(t_main *mapData)
{
	drawMap(mapData);
	putPlayer(mapData);
}

int	checkExtension(char *filename)
{
	int i;

	i = (int)ft_strlen(filename) - 3;
	if (filename[i] == 'b')
		i++;
	if (filename[i] == 'e')
		i++;
	if (filename[i] == 'r')
		return (1);
	else
		return (0);
}

int checkMapSymbols(t_main *mapData)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == '1' ||mapData->map[i][j] == '0' || mapData->map[i][j] == 'E' ||
					mapData->map[i][j] == 'C' || mapData->map[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int checkMapSize(t_main *mapData, int argc)
{
	int i;

	i = 1;
	int len  = (int)ft_strlen(mapData->map[0]);
	while (mapData->map[i])
	{
		if (ft_strlen(mapData->map[i]) != len)
			return (0);
		//printf("%d - длина i\n", (int)ft_strlen(mapData->map[i]));
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_main *mapData;
	int fd;
	int n;
	int i;
	int j;
	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments\n");
		exit(1);
	}
	if (!checkExtension(argv[1]))
	{
		ft_putstr("Error: bad file extension\n");
		exit(1);
	}
	n = 1;
	i = 0;
	j = 0;
//	printf("sdrgewgw\n");
	mapData = structInit();
	mapData->mlx = mlx_init();
//	printf("sdrgewgw\n");
	mapData->height = getMapHeight(argv[1]);
	mapData->width = getMapWidth(argv[1]);
//	printf("%d\n", mapData->width);
//	printf("%d\n", mapData->height);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) // добавить проверку на расширение .ber
	{
		ft_putstr("Error: bad file\n");
		exit(1);
	}
	mapData->map = (char **)malloc(sizeof(char *) * (mapData->height + 1));
	if (!mapData->map)
	{
		free (mapData->map);
		exit(1);
	}
	ft_bzero(mapData->map, (sizeof(char *) * (mapData->height + 1)));
	while (n > 0) //getMap
	{
		n = get_next_line(fd, &mapData->map[i]);
		i++;
	}
	close(fd);
	if (!checkMapSymbols(mapData))
	{
		ft_putstr("Error: wrong map\n");
		//free(mapData); //добавить везде универсальную очистку
		exit(1);
	}
	if (!checkMapSize(mapData, argc))
	{
		ft_putstr("Error: wrong map size\n");
		//free(mapData); //добавить везде универсальную очистку
		exit(1);
	}
	locatePlayer(mapData);
	printf("%d\n", mapData->player->x);
	printf("%d\n", mapData->player->y);
	mapData->mlx_win = mlx_new_window(mapData->mlx, mapData->width * 32, mapData->height * 32, "so_long");
//	drawMap(mapData);
	mlx_string_put(mapData->mlx, mapData->mlx_win, 30, 30, 99999, "hello");
	mlx_key_hook(mapData->mlx_win, key_hook, mapData);
	mlx_loop_hook(mapData->mlx, render_next_frame, mapData);
	mlx_hook(mapData->mlx_win, 17, 5, ft_exit, mapData); //red cross exit
//	printf("%s\n", mapData->map[0]);
//	printf("%s\n", mapData->map[1]);
//	printf("%s\n", mapData->map[2]);
//	printf("%s\n", mapData->map[3]);
//	printf("%s\n", mapData->map[4]);
//	printf("%s\n", mapData->map[5]);
	//mlx_hook(mapData->mlx_win, 17, 0L, ft_exit(), mapData); //red cross exit
	//mlx_hook(mapData->mlx_win, 17, 5, ft_exit(), mapData); //red cross exit
	mlx_loop(mapData->mlx);
	free(mapData->mlx);
	while (j < i) //freeMap, возможна утечка
	{
		free(mapData->map[j]);
		j++;
	}
	free(mapData->map);
	structFree(mapData);
	return (SUCCESS);
}