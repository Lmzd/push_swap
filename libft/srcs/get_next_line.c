/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:09:53 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/03 20:04:31 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_readfile(char **gnl, char *buf, int fd)
{
	char			*tmp;
	unsigned int	nb;

	nb = 1;
	while (!(ft_strchr(*gnl, '\n')) && nb)
	{
		nb = read(fd, buf, BUFF_SIZE);
		if (nb)
		{
			buf[nb] = '\0';
			tmp = *gnl;
			if (!(*gnl = ft_strjoin(*gnl, buf)))
				return (NULL);
			free(tmp);
		}
	}
	free(buf);
	return (*gnl);
}

char			*stock_line(char **gnl)
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

int				get_next_line(const int fd, char **line)
{
	static char	*gnl = NULL;
	char		*buf;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if ((gnl == NULL && !(gnl = ft_strnew(0))))
		return (-1);
	if (!(ft_readfile(&gnl, buf, fd)))
		return (-1);
	if (*gnl)
	{
		if (!(*line = stock_line(&gnl)))
			return (-1);
		return (1);
	}
	return (0);
}
