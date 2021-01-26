/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrandie <hbrandie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:49:06 by jasougi           #+#    #+#             */
/*   Updated: 2021/01/24 16:35:48 by hbrandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char			*ft_check(char *rem, char **line)
{
	char		*pointer;

	pointer = NULL;
	if (rem[0])
	{
		if ((pointer = ft_strchr(rem)))
		{
			*pointer = '\0';
			if (!(*line = ft_strdup(rem)))
				return (NULL);
			ft_memmove(rem, (pointer + 1), BUFFER_SIZE - (pointer - rem));
		}
		else
		{
			if (!(*line = ft_strdup(rem)))
				return (NULL);
		}
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		*line[0] = '\0';
	}
	return (pointer);
}

int				ft_connect(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (0);
	free(tmp);
	return (1);
}

char			*ft_search(char **line, char *buf)
{
	char		*p;

	p = NULL;
	if ((p = ft_strchr(buf)))
	{
		*p = '\0';
		if (!ft_connect(line, buf))
			return (NULL);
		p += 1;
		ft_memmove(buf, p, BUFFER_SIZE - (p - buf) + 1);
	}
	else
	{
		if (!ft_connect(line, buf))
			return (NULL);
		buf[0] = '\0';
	}
	return (p);
}

int				get_next_line(int fd, 	char **line)
{
	int			read_fd;
	static char	buf[((BUFFER_SIZE) < 1) ? (1) : (BUFFER_SIZE + 1)] = {0};
	char		*pointer;

	if (BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1) || line == NULL)
		return (-1);
	pointer = ft_check(buf, line);
	if (line == NULL)
		return (-1);
	read_fd = -1;
	while (!pointer && (read_fd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_fd] = '\0';
		pointer = ft_search(line, buf);
		if (line == NULL)
			return (-1);
	}
	if (read_fd == 0 && buf[0] == '\0')
		return (0);
	return (1);
}

