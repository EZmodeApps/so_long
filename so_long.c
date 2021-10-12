//
// Created by Ilya on 10.10.2021.
//

#include "so_long.h"

t_map *mapStructInit(void)
{
	t_map *mapData;

	mapData = malloc(sizeof(t_map));
	mapData->map = NULL;
	mapData->size = 0;
	return(mapData);
}

void structFree(t_map *mapData)
{
	mapData->map = NULL;
	mapData->size = NULL;
	free(mapData);
}

int main(void)
{
	t_map *mapData;
	int fd;
	int n;
	char *line;

	mapData = mapStructInit();
	fd = open("/Users/ez_mode/Developer/GitHub/so_long/map.txt", O_RDONLY);
	while ((n = get_next_line(fd, &line)) > 0)
	{
		mapData->map = line;
		printf("%s\n", line);
		free(line);
	}
	if (!n)
	{
		printf("%s", line);
		free(line);
	}
	n = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("\n");
	printf("%s\n", mapData->map);
	printf("1\n");
	close(fd);
	return (0);
}