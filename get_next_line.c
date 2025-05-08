#include "get_next_line.h"

char	*initialize(char *stash, int *eol)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		*eol = i - 1;
	return (line);
}

size_t	find_eol(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*extract(char *line, char *stash, int *eol, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_check;
	size_t	line_size;

	while (*eol == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			ft_bzero(stash, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_size = find_eol(buffer);
		ft_strlcpy(stash, &buffer[line_size], (BUFFER_SIZE + 1));
		buffer[line_size] = '\0';
		line = ft_strjoin(line, buffer, eol);
		if (read_check == 0)
		{
			ft_bzero(stash, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	int			eol;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	eol = -1;
	line = initialize(stash, &eol);
	if (!line)
		return (NULL);
	ft_strlcpy(stash, &stash[eol + 1], BUFFER_SIZE + 1);
	line = extract(line, stash, &eol, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
