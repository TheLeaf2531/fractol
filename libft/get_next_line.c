/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:44:57 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/20 19:21:36 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char			*cpy;

	if ((cpy = (char*)malloc(sizeof(*cpy) * (n + 1))) == 0)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char					*read_gnl(char **gnl, char *buf, int fd)
{
	char		*tmp;
	int			ret;

	ret = 1;
	while (!(ft_strchr(*gnl, '\n')) && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret)
		{
			buf[ret] = '\0';
			tmp = *gnl;
			if (!(*gnl = ft_strjoin(*gnl, buf)))
				return (NULL);
			free(tmp);
		}
	}
	free(buf);
	return (*gnl);
}

char					*stock_line(char **gnl)
{
	char		*buf;
	char		*newline;
	char		*tmp;

	buf = ft_strchr(*gnl, '\n');
	tmp = NULL;
	if (buf)
	{
		if (!(newline = ft_strndup(*gnl, buf - *gnl)))
			return (NULL);
		tmp = *gnl;
		if (!(*gnl = ft_strdup(buf + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(newline = ft_strdup(*gnl)))
		return (NULL);
	if (!(*gnl) || !tmp)
	{
		free(*gnl);
		*gnl = NULL;
	}
	return (newline);
}

int						get_next_line(const int fd, char **line)
{
	static char	*gnl = NULL;
	char		*buf;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE + 1)) \
		|| read(fd, buf, 0) == -1 || (gnl == NULL && !(gnl = ft_strnew(0))))
		return (-1);
	if (!(read_gnl(&gnl, buf, fd)))
		return (-1);
	if (*gnl)
	{
		if (!(*line = stock_line(&gnl)))
			return (-1);
		return (1);
	}
	return (0);
}
