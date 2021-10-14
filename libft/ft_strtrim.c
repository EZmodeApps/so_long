/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:23:38 by caniseed          #+#    #+#             */
/*   Updated: 2021/08/11 22:23:39 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_to_find(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	beg;
	size_t	l;
	char	*res;

	l = ft_strlen(s1);
	i = 0;
	beg = 0;
	if (s1 == NULL || set == NULL)
		return ((char *)s1);
	while (s1[beg] && ft_to_find(set, s1[beg]))
		beg++;
	while (l > beg && ft_to_find(set, s1[l - 1]))
		l--;
	res = (char *)malloc(sizeof(char) * (l - beg + 1));
	if (!res)
		return (NULL);
	while (beg < l)
	{
		res[i] = s1[beg];
		beg++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
