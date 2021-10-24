/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:45:48 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:45:48 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (mapData->map[i][j] == '1' || mapData->map[i][j] == '0' ||
				mapData->map[i][j] == 'E' || mapData->map[i][j] == 'C' ||
				mapData->map[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int	checkMapSize(t_main *mapData)
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
		if (mapData->map[i][0] == '1' &&
			mapData->map[i][mapData->size_x - 1] == '1')
			midWall++;
		i++;
	}
	if (midWall == mapData->size_y - 2 && topWall == mapData->size_x
		&& bottomWall == mapData->size_x)
		return (1);
	else
		return (0);
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