#include "../so_long.h"

size_t	strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*strjoin_gnl(char *saved_buf, char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (strlen_gnl(saved_buf) + strlen_gnl(buf) + 1));
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

