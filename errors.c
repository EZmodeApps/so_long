/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:40:02 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:40:02 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkMap2(t_main *mapData)
{
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
}

void	checkMap(t_main *mapData)
{
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
	checkMap2(mapData);
}

void	handleErrors(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr("Error: wrong number of arguments!\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: bad file!\n");
		close(fd);
		exit(ERROR);
	}
	if (!checkExtension(filename))
	{
		ft_putstr("Error: bad file extension!\n");
		close(fd);
		exit(1);
	}
	close(fd);
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