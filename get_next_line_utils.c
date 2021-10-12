#include "so_long.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *saved_buf, char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(saved_buf) + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	if (saved_buf)
	{
		while (saved_buf[i])
		{
			res[i] = saved_buf[i];
			i++;
		}
	}
	if (buf)
	{
		while (buf[j])
			res[i++] = buf[j++];
	}
	res[i] = '\0';
	free(saved_buf);
	return (res);
}

