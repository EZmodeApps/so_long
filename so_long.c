//
// Created by EZmodeApps on 10.10.2021.
//

#include "./so_long.h"

t_main *mapStructInit(void)
{
	t_main *mapData;

	mapData = malloc(sizeof(t_main));
	mapData->map = NULL;
	mapData->player = NULL;
	mapData->size_x = 0;
	mapData->size_y = 0;
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
	int fd;
	int n;

	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments\n");
		exit(1);
	}
	n = 1;
	mapData = mapStructInit();
	fd = open(argv[1], O_RDONLY);
	while (n > 0)
	{
		n = get_next_line(fd, &mapData->map);
		drawMap(mapData);
//		printf("%s\n", mapData->map);
		free(mapData->map);
	}
	close(fd);
	structFree(mapData);
	return (0);
}