/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:16:12 by kchabala          #+#    #+#             */
/*   Updated: 2018/06/28 08:39:45 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_check_line(char **string, char **line, int fd)
{
	char			*temp;
	int				length;

	length = 0;
	while (string[fd][length] != '\n' && string[fd][length] != '\0')
		length++;
	if (string[fd][length] == '\n')
	{
		*line = ft_strsub(string[fd], 0, length);
		temp = ft_strdup(string[fd] + length + 1);
		free(string[fd]);
		string[fd] = temp;
		if (string[fd][0] == '\0')
			ft_strdel(&string[fd]);
	}
	else if (string[fd][length] == '\0')
	{
		if (length == 0)
			return (0);
		*line = ft_strdup(string[fd]);
		ft_strdel(&string[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[255];
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	int				result;

	if (fd < 0 || line == NULL || (result = read(fd, buf, 0)) < 0
			|| BUFF_SIZE <= 0)
		return (-1);
	while ((result = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[result] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (result == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_check_line(str, line, fd));
}
