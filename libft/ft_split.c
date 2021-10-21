/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	size_t	word_counter;

	i = 0;
	word_counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word_counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_counter);
}

static char	**ft_memfree(char **res)
{
	int	i;

	i = 0;
	if (res[i])
	{
		while (res[i])
		{
			free(res[i]);
			res[i] = NULL;
			i++;
		}
		free(res);
		res = NULL;
	}
	return (NULL);
}

static char	*ft_create_word(char const *s, size_t d)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (d + 1));
	if (word)
	{
		while (s[i] && i < d)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
		return (word);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	del;
	size_t	size;

	i = 0;
	size = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		del = i;
		while (s[i] && s[i] != c)
			i++;
		if (del < i)
			*res++ = ft_create_word(s + del, i - del);
		if (!ft_create_word(s + del, i - del))
			return (ft_memfree(res));
	}
	*res = NULL;
	return (res - size);
}
