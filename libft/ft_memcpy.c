/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		c[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (c);
}
