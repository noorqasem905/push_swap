/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:59:00 by yhamdan           #+#    #+#             */
/*   Updated: 2024/10/07 18:27:49 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextline(char *buf, char *l)
{
	size_t	i;
	size_t	j;
	char	*rem;

	if (!l || !buf)
		return (NULL);
	i = ft_strlen(l);
	j = 0;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	while (buf[i++])
		j++;
	rem = malloc((j + 1));
	i = ft_strlen(l);
	j = 0;
	while (buf[i + j])
	{
		rem[j] = buf[i + j];
		j++;
	}
	rem[j] = '\0';
	return (free(buf), rem);
}

char	*ft_line(char *res)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!res)
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buf)
{
	char	*temp;
	ssize_t	bytread;

	bytread = 1;
	while (bytread > 0 && !ft_strchr_vline(buf))
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		bytread = read(fd, temp, BUFFER_SIZE);
		if (bytread == -1 || (!buf && bytread == 0))
		{
			free(temp);
			return (NULL);
		}
		temp[bytread] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read(fd, buf);
	if (!temp)
	{
		if (buf)
			free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = temp;
	line = ft_line(buf);
	buf = ft_nextline(buf, line);
	return (line);
}

/*
int	main()
{

	int fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		char *line;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	} else {
		printf("Error Opening File\n");
		return (-1);
	}
	return (0);
}*/
