/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/22 22:31:47 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_main	*mapDataInit(void)
{
	t_main	*mapData;

	mapData = malloc(sizeof(t_main));
	mapData->map = NULL;
	mapData->mlx = NULL;
	mapData->mlx_win = NULL;
	mapData->player = (t_player *)malloc(sizeof(t_player));
	mapData->player->x = 0;
	mapData->player->y = 0;
	mapData->size_x = 0;
	mapData->size_y = 0;
	mapData->collectibles = 0;
	mapData->num_of_players = 0;
	mapData->exit = 0;
	mapData->moves = 0;
	return (mapData);
}

void	freeMap(t_main *mapData)
{
	int	i;

	i = 0;
	while (i < mapData->size_y)
	{
		free(mapData->map[i]);
		i++;
	}
	free(mapData->map);
}

void	structFree(t_main *mapData)
{
	freeMap(mapData);
	free(mapData->mlx);
	mapData->size_x = 0;
	mapData->size_y = 0;
	mapData->collectibles = 0;
	mapData->num_of_players = 0;
	mapData->exit = 0;
	mapData->moves = 0;
	mapData->player->x = 0;
	mapData->player->y = 0;
	free(mapData->player);
	free(mapData);
}

int	ft_exit(t_main *mapData)
{
	structFree(mapData);
	exit (SUCCESS);
}

void	drawMap(t_main *mapData)
{
	int		i;
	int		x;
	int		y;
	int		j;
	void	*picWall;
	void	*picFloor;
	void	*picExit;
	void	*picCollectible;
	int		pic_width;
	int		pic_height;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	//y = 32;
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

void	putPlayer(t_main *mapData)
{
	int		pic_width;
	int		pic_height;
	void	*picPlayer;

	picPlayer = mlx_xpm_file_to_image(mapData->mlx, PLAYER_1, &pic_width, &pic_height);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picPlayer, mapData->player->x * 32, mapData->player->y * 32);
}

int	getMapHeight(char *mapInput)
{
	int		n;
	int		fd;
	int		counter;
	char	*line;

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

int	getMapWidth(char *mapInput)
{
	int		length;
	int		fd;
	char	*line;

	length = 0;
	fd = open(mapInput, O_RDONLY);
	get_next_line(fd, &line);
	length = (int)ft_strlen(line);
	free (line);
	return (length);
}

void	locatePlayer(t_main *mapData)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == 'P')
			{
				mapData->player->x = j;
				mapData->player->y = i;
				mapData->num_of_players++;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	countCollectibles(t_main *mapData)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == 'C')
				mapData->collectibles++;
			j++;
		}
		i++;
		j = 0;
	}
}

void	countExit(t_main *mapData)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == 'E')
				mapData->exit++;
			j++;
		}
		i++;
		j = 0;
	}
}

int	key_hook(int keycode, t_main *mapData)
{
	if (keycode == ESC)
	{
		mlx_clear_window(mapData->mlx, mapData->mlx_win);
		mlx_destroy_window(mapData->mlx, mapData->mlx_win);
		structFree(mapData);
		exit(SUCCESS);
	}
	if (keycode == W)
		if (mapData->map[mapData->player->y - 1][mapData->player->x] != '1') {
			if (mapData->map[mapData->player->y - 1][mapData->player->x] == 'C')
			{
				mapData->map[mapData->player->y - 1][mapData->player->x] = '0';
				mapData->collectibles--;
			}
			if (mapData->collectibles == 0 && mapData->map[mapData->player->y - 1][mapData->player->x] == 'E')
			{
				mlx_clear_window(mapData->mlx, mapData->mlx_win);
				mlx_destroy_window(mapData->mlx, mapData->mlx_win);
				structFree(mapData);
				exit(SUCCESS);
			}
			mapData->player->y -= 1;
			mapData->moves++;
		}
	if (keycode == S)
		if (mapData->map[mapData->player->y + 1][mapData->player->x] != '1') {
			if (mapData->map[mapData->player->y + 1][mapData->player->x] == 'C')
			{
				mapData->map[mapData->player->y + 1][mapData->player->x] = '0';
				mapData->collectibles--;
			}
			if (mapData->collectibles == 0 && mapData->map[mapData->player->y + 1][mapData->player->x] == 'E')
			{
				mlx_clear_window(mapData->mlx, mapData->mlx_win);
				mlx_destroy_window(mapData->mlx, mapData->mlx_win);
				structFree(mapData);
				exit(SUCCESS);
			}
			mapData->player->y += 1;
			mapData->moves++;
		}
	if (keycode == D)
		if (mapData->map[mapData->player->y][mapData->player->x + 1] != '1') {
			if (mapData->map[mapData->player->y][mapData->player->x + 1] == 'C')
			{
				mapData->map[mapData->player->y][mapData->player->x + 1] = '0';
				mapData->collectibles--;
			}
			if (mapData->collectibles == 0 && mapData->map[mapData->player->y][mapData->player->x + 1] == 'E')
			{
				mlx_clear_window(mapData->mlx, mapData->mlx_win);
				mlx_destroy_window(mapData->mlx, mapData->mlx_win);
				structFree(mapData);
				exit(SUCCESS);
			}
			mapData->player->x += 1;
			mapData->moves++;
		}
	if (keycode == A)
		if (mapData->map[mapData->player->y][mapData->player->x - 1] != '1') {
			if (mapData->map[mapData->player->y][mapData->player->x - 1] == 'C')
			{
				mapData->map[mapData->player->y][mapData->player->x - 1] = '0';
				mapData->collectibles--;
			}
			if (mapData->collectibles == 0 && mapData->map[mapData->player->y][mapData->player->x - 1] == 'E')
			{
				mlx_clear_window(mapData->mlx, mapData->mlx_win);
				mlx_destroy_window(mapData->mlx, mapData->mlx_win);
				structFree(mapData);
				exit(SUCCESS);
			}
			mapData->player->x -= 1;
			mapData->moves++;
		}
	printf("Your score is: %d.\n", mapData->moves);
	//printf("%d\n", keycode);
	return (0);
}

int	render_next_frame(t_main *mapData)
{
	drawMap(mapData);
	putPlayer(mapData);
	return (0);
}

int	checkExtension(char *filename)
{
	int	i;

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

int	checkMapSymbols(t_main *mapData)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == '1' || mapData->map[i][j] == '0' || mapData->map[i][j] == 'E' ||
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

int checkMapSize(t_main *mapData)
{
	int	i;
	int	len;

	i = 1;
	len = (int)ft_strlen(mapData->map[0]);
	while (mapData->map[i])
	{
		if ((int)ft_strlen(mapData->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	checkWalls(t_main *mapData)
{
	int	i;
	int	topWall;
	int	bottomWall;
	int	midWall;

	i = 1;
	topWall = 0;
	bottomWall = 0;
	midWall = 0;
	while (mapData->map[0][topWall] == '1')
		topWall++;
	while (mapData->map[mapData->size_y - 1][bottomWall] == '1')
		bottomWall++;
	while (i < mapData->size_y - 1)
	{
		if (mapData->map[i][0] == '1' && mapData->map[i][mapData->size_x - 1] == '1')
			midWall++;
		i++;
	}
	if (midWall == mapData->size_y - 2 && topWall == mapData->size_x && bottomWall == mapData->size_x)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_main	*mapData;
	int		fd;
	int		n;
	int		i;
	int		j;

	n = 1;
	i = 0;
	j = 0;
	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments!\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: bad file!\n");
		close(fd);
		exit(ERROR);
	}
	if (!checkExtension(argv[1]))
	{
		ft_putstr("Error: bad file extension!\n");
		close(fd);
		exit(1);
	}
	mapData = mapDataInit();
	mapData->mlx = mlx_init();
	mapData->size_y = getMapHeight(argv[1]);
	mapData->size_x = getMapWidth(argv[1]);
//	printf("%d\n", mapData->size_x);
//	printf("%d\n", mapData->size_y);
	mapData->map = (char **)malloc(sizeof(char *) * (mapData->size_y + 1));
	if (!mapData->map)
	{
		structFree(mapData);
		close(fd);
		exit(ERROR);
	}
	ft_bzero(mapData->map, (sizeof(char *) * (mapData->size_y + 1)));
	while (n > 0) //getMap
	{
		n = get_next_line(fd, &mapData->map[i]);
		i++;
	}
	close(fd);
	if (!checkMapSymbols(mapData))
	{
		ft_putstr("Error: wrong map!\n");
		structFree(mapData);
		exit(ERROR);
	}
	if (!checkMapSize(mapData))
	{
		ft_putstr("Error: wrong map size!\n");
		structFree(mapData);
		exit(ERROR);
	}
	if (!checkWalls(mapData))
	{
		ft_putstr("Error: map is not surrounded by walls!\n");
		structFree(mapData);
		exit(ERROR);
	}
	locatePlayer(mapData);
	if (mapData->num_of_players > 1)
	{
		ft_putstr("Error: too many players!\n");
		structFree(mapData);
		exit(ERROR);
	}
	countCollectibles(mapData);
	if (mapData->collectibles < 1)
	{
		ft_putstr("Error: wrong quantity of collectables!\n");
		structFree(mapData);
		exit(ERROR);
	}
	countExit(mapData);
	if (mapData->exit < 1)
	{
		ft_putstr("Error: wrong quantity of exits!\n");
		structFree(mapData);
		exit (ERROR);
	}
	//mapData->mlx_win = mlx_new_window(mapData->mlx, mapData->size_x * 32, (mapData->size_y + 1) * 32, "so_long"); //для putstring mlx score
	mapData->mlx_win = mlx_new_window(mapData->mlx, mapData->size_x * 32, mapData->size_y * 32, "so_long");
	//mlx_string_put(mapData->mlx, mapData->mlx_win, 50, 50, 99999, ft_itoa(mapData->moves));
	mlx_key_hook(mapData->mlx_win, key_hook, mapData);
	mlx_loop_hook(mapData->mlx, render_next_frame, mapData);
	//mlx_hook(mapData->mlx_win, 17, 5, ft_exit, mapData); //do i need it anymore?
	mlx_loop(mapData->mlx);
	return (SUCCESS);
}