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
	mapData->player = (t_player *)malloc(sizeof(t_player));
	mapData->player->x = 0;
	mapData->player->y = 0;
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
	free(mapData->player);
	mapData->player->x = 0;
	mapData->player->y = 0;
	free(mapData);
}

void drawMap(t_main *mapData, void *mlx, void *mlx_win)
{
	int i;
	int x;
	int y;
	int j;
	void *picWall;
	void *picFloor;
	void *picPlayer;
	void *picExit;
	void *picCollectible;
	int pic_width;
	int pic_height;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	printf("1111\n");
	picWall = mlx_xpm_file_to_image(mlx, WALL, &pic_width, &pic_height);
	picFloor = mlx_xpm_file_to_image(mlx, FLOOR, &pic_width, &pic_height);
	picPlayer = mlx_xpm_file_to_image(mlx, PLAYER_1, &pic_width, &pic_height);
	picExit = mlx_xpm_file_to_image(mlx, EXIT, &pic_width, &pic_height);
	picCollectible = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &pic_width, &pic_height);
	//	while (j < mapData->height)
	while (mapData->map[j])
	{
		//printf("j = %d\n", j);
		i = 0;
		x = 0;
		while (mapData->map[j][i])
		{
			//printf("i = %d\n", i);
			if (mapData->map[j][i] == '0') {
				mlx_put_image_to_window(mlx, mlx_win, picFloor, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == '1') {
				mlx_put_image_to_window(mlx, mlx_win, picWall, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == 'E') {
				mlx_put_image_to_window(mlx, mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mlx, mlx_win, picExit, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == 'C') {
				mlx_put_image_to_window(mlx, mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mlx, mlx_win, picCollectible, x, y);
				x += 32;
			}
			if (mapData->map[j][i] == 'P') {
				mlx_put_image_to_window(mlx, mlx_win, picFloor, x, y);
				mlx_put_image_to_window(mlx, mlx_win, picPlayer, x, y);
				x += 32;
			}
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

void	key_hook(int keycode, t_main *mapData)
{
	int pic_width;
	int pic_height;
	void *picPlayer = mlx_xpm_file_to_image(mapData->mlx, PLAYER_1, &pic_width, &pic_height);
	//(t_main *)mapData;
	if (keycode == W)
		printf("W is pressed\n");
	if (keycode == D) {
		mapData->player->x += 32;
		mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picPlayer, mapData->player->x, mapData->player->y);
		printf("%d\n", mapData->player->y);
	}
	printf("%d\n", keycode);
}

int main(int argc, char **argv)
{
	t_main *mapData;
//	void *mlx;
//	void *mlx_win;
	int fd;
	int n;
	int i;
	int j;
	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments\n");
		exit(1);
	}
//	checkMapValidity();
	n = 1;
	i = 0;
	j = 0;
	//mlx = mlx_init();
//	printf("sdrgewgw\n");
	mapData = mapStructInit();
	mapData->mlx = mlx_init();
//	printf("sdrgewgw\n");
	mapData->height = getMapHeight(argv[1]);
	mapData->width = getMapWidth(argv[1]);
//	printf("%d\n", mapData->width);
//	printf("%d\n", mapData->height);
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
		exit(1);
	}
	ft_bzero(mapData->map, (sizeof(char *) * (mapData->height + 1)));
	while (n > 0) //getMap
	{
		n = get_next_line(fd, &mapData->map[i]);
		i++;
	}
	close(fd);
	locatePlayer(mapData);
	printf("%d\n", mapData->player->x);
	printf("%d\n", mapData->player->y);
//	mlx_win = mlx_new_window(mlx, mapData->width * 32, mapData->height * 32, "so_long");
	mapData->mlx_win = mlx_new_window(mapData->mlx, mapData->width * 32, mapData->height * 32, "so_long");
	drawMap(mapData, mapData->mlx, mapData->mlx_win);
	mlx_string_put(mapData->mlx, mapData->mlx_win, 30, 30, 99999, "hello");
	mlx_key_hook(mapData->mlx_win, key_hook, mapData);
//	printf("%s\n", mapData->map[0]);
//	printf("%s\n", mapData->map[1]);
//	printf("%s\n", mapData->map[2]);
//	printf("%s\n", mapData->map[3]);
//	printf("%s\n", mapData->map[4]);
//	printf("%s\n", mapData->map[5]);
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