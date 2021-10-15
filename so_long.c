//
// Created by EZmodeApps on 10.10.2021.
//

#include "so_long.h"


t_main *mapStructInit(void)
{
	t_main *mapData;

	mapData = malloc(sizeof(t_main));
	mapData->map = NULL;
	mapData->player = NULL;
	mapData->size_x = 0;
	mapData->size_y = -1;
	return(mapData);
}

void structFree(t_main *mapData)
{
	mapData->map = NULL;
	mapData->player = NULL;
	mapData->size_x = 0;
	mapData->size_y = 0;
	free(mapData);
}

void drawMap(t_main *mapData)
{
	int i = 0;
	char *line = mapData->map;

	while (line[i])
	{
		if (line[i] == '1')
		{
			printf("%c", line[i]);
		}
		if (line[i] == '0')
		{
			printf("%c", line[i]);
		}
		if (line[i] == '\n')
		{
			printf("\n");
		}
		if (line[i] == 'E')
		{
			printf("%c", line[i]);
		}
		if (line[i] == 'C')
		{
			printf("%c", line[i]);
		}
		if (line[i] == 'P')
		{
			printf("%c", line[i]);
		}
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_main *mapData;
	void *mlx;
	char *mapp;
	char *temp;
	//void *mlx_win;
	int fd;
	int n;
	int row_counter;

	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments\n");
		exit(1);
	}
	n = 1;
	row_counter = 0;
	mlx = mlx_init();
	mapData = mapStructInit();
	fd = open(argv[1], O_RDONLY);
	while (n > 0)
	{
//		mapData->size_y++;
		n = get_next_line(fd, &mapData->map);
//		drawMap(mapData);
//		mapData->size_x = ft_strlen(mapData->map);
		mapp = strjoin_gnl(mapp, mapData->map);
		temp = mapp;
		mapp = strjoin_gnl(mapp, "\n");
		free(temp);
//		printf("%d\n", mapData->size_x);
//		printf("%s\n", mapData->map);
		free(mapData->map);
	}
	printf("%d\n", mapData->size_x);
	printf("%d\n", mapData->size_y);
	printf("%s\n", mapp);
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
	close(fd);
	free(mapp);
	structFree(mapData);
	return (0);
}