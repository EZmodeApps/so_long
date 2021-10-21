/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (void *)malloc(count * size);
	if (!res)
		return (NULL);
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (((void *)res));
}
