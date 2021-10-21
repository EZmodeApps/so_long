/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len > 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == (unsigned char)c)
		return ((char *)&s[len]);
	return (NULL);
}
