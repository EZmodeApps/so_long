/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new)
		{
			while (s[i])
			{
				new[i] = f(i, s[i]);
				i++;
			}
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
