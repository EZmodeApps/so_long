/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:22:54 by caniseed          #+#    #+#             */
/*   Updated: 2021/08/11 22:22:55 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j])
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if ((size_t)(i + j - 1) < len)
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
