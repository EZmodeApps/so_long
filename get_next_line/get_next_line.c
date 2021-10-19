#include "../so_long.h"

char	*get_line(char *saved_buf)
{
	int		i;
	char	*new_line;

	i = 0;
	while (saved_buf && saved_buf[i] && saved_buf[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (saved_buf && saved_buf[i] && saved_buf[i] != '\n')
	{
		new_line[i] = saved_buf[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*clear_saved_buf(char *saved_buf)
{
	int		i;
	int		j;
	size_t	length;
	char	*new_buf;

	i = 0;
	if (!saved_buf)
		return (NULL);
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (saved_buf[i] == '\0')
	{
		free(saved_buf);
		return (NULL);
	}
	length = strlen_gnl(saved_buf) - i;
	new_buf = malloc(sizeof(char) * (length + 1));
	if (!new_buf)
		return (NULL);
	i++, j = 0;
	while (saved_buf[i])
		new_buf[j++] = saved_buf[i++];
	new_buf[j] = '\0';
	free(saved_buf);
	return (new_buf);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		bytes;
	static char	*saved_buf;
	char		*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		saved_buf = strjoin_gnl(saved_buf, buf);
		if (ft_strchr(saved_buf, '\n'))
			break;
	}
	free(buf);
	*line = get_line(saved_buf);
	saved_buf = clear_saved_buf(saved_buf);
	if (bytes == 0 && !saved_buf)
		return (0);
	return (1);
}

