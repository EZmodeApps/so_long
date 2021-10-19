/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:20 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/19 22:01:48 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_main *mapStructInit(void)
{
	t_main *mapData;

	mapData = malloc(sizeof(t_main));
	mapData->map = NULL;
	mapData->player = NULL;
	mapData->width = 0;
	mapData->height = 0;
	return(mapData);
}

void structFree(t_main *mapData)
{
	mapData->map = NULL;
	mapData->mlx = NULL;
	mapData->mlx_win = NULL;
	mapData->width = 0;
	mapData->height = 0;
	mapData->player = NULL;
	free(mapData);
}

void drawMap(t_main *mapData, void *mlx, void *mlx_win)
{
	int i;
	int x = 0;
	int y = 0;
	int j;
	void *picWall;
	void *picFloor;
	char *picPath = "/Users/caniseed/Desktop/so_long/so_long/textures/wall.xpm";
	char *picPath2 = "/Users/caniseed/Desktop/so_long/so_long/textures/floor.xpm";
	int pic_width;
	int pic_height;

	i = 0;
	j = 0;
	picWall = mlx_xpm_file_to_image(mlx, picPath, &pic_width, &pic_height);
	picFloor = mlx_xpm_file_to_image(mlx, picPath2, &pic_width, &pic_height);
	while (mapData->map[j])
//	while (j < mapData->height)
	{
		i = 0;
		x = 0;
		while (mapData->map[j][i])
		{
//			printf("1\n");
			if (mapData->map[j][i] == '1')
			{
				mlx_put_image_to_window(mlx, mlx_win, picWall, x, y);
				x += 32;
			}
			else
			{
				mlx_put_image_to_window(mlx, mlx_win, picFloor, x, y);
				x += 32;
			}
//			if (mapData->map[i] == '0') {
//				printf("%c", mapData->map[i]);
//			}
//			if (mapData->map[i] == '\n') {
//				printf("\n");
//			}
//			if (mapData->map[i] == 'E') {
//				printf("%c", mapData->map[i]);
//			}
//			if (mapData->map[i] == 'C') {
//				printf("%c", mapData->map[i]);
//			}
//			if (mapData->map[i] == 'P') {
//				printf("%c", mapData->map[i]);
				i++;
			}
		j++;
		y += 32;
	}
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

int	key_hook(int keycode)//, t_main *mapData)
{
	//(t_main *)mapData;
	if (keycode == ESC)
		exit(2);
	printf("%d\n", keycode);
	return (9);
}

int main(int argc, char **argv)
{
	t_main *mapData;
	//char *pic_path = "/Users/caniseed/Desktop/so_long/so_long/3333333.xpm";
	//void *pic;
	void *mlx;
	void *mlx_win;
	int fd;
	int n;
	int i;
	int j;
	//int pic_width;
//	int pic_height;

	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments\n");
		exit(1);
	}
//	checkMapValidity();
	n = 1;
	i = 0;
	j = 0;
	mlx = mlx_init();
	mapData = mapStructInit();
	mapData->height = getMapHeight(argv[1]);
	mapData->width = getMapWidth(argv[1]);
	printf("%d\n", mapData->width);
	printf("%d\n", mapData->height);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: bad file\n");
		exit(1);
	}
	mapData->map = (char **)malloc(sizeof(char *) * (mapData->height + 1));//возможно ошибка с выделением памяти ?
	if (!mapData->map)
	{
		free (mapData->map);
		exit (1);
	}
	ft_bzero(mapData->map, (sizeof(char *) * (mapData->height + 1)));
	while (n > 0) //getMap
	{
		n = get_next_line(fd, &mapData->map[i]);
		i++;
	}
	close(fd);
//	locatePlayer(mapData);
//	printf("%d\n", mapData->player->x);
//	printf("%d\n", mapData->player->y);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	drawMap(mapData, mlx, mlx_win);
//	pic = mlx_xpm_file_to_image(mlx, pic_path, &pic_width, &pic_height);
//	mlx_put_image_to_window(mlx, mlx_win, pic, 0, 0);
//	mlx_xpm_file_to_image(mlx, pic, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, pic, 0, 0);
	mlx_string_put(mlx, mlx_win, 30, 30, 99999, "hello");
	//mlx_key_hook(mlx_win, key_hook, mapData);
	printf("%s\n", mapData->map[0]);
	printf("%s\n", mapData->map[1]);
	printf("%s\n", mapData->map[2]);
	printf("%s\n", mapData->map[3]);
	printf("%s\n", mapData->map[4]);
	printf("%s\n", mapData->map[5]);
	mlx_loop(mlx);
	free(mlx);
	while (j < i) //freeMap, возможна утечка
	{
		free(mapData->map[j]);
		j++;
	}
	free(mapData->map);
	structFree(mapData);
	return (SUCCESS);
}
