/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:50:50 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:50:50 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	getMap(t_main *mapData, char *map)
{
	int	fd;
	int	n;
	int	i;

	n = 1;
	i = 0;
	fd = open(map, O_RDONLY);
	while (n > 0)
	{
		n = get_next_line(fd, &mapData->map[i]);
		i++;
	}
	close(fd);
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
	close(fd);
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
	close (fd);
	return (length);
}