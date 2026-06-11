/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:54:57 by dthan             #+#    #+#             */
/*   Updated: 2026/05/29 15:17:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"
#define BUFF_SIZE 1000
#define FD_MAX 256

static int	valid_fd(int fd)
{
	int	flags;

	flags = fcntl(fd, F_GETFL);
	return (flags != -1);
}

static int	has_line_break(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

static int	read_to_storage(int fd, char **storage)
{
	char	buffer[BUFF_SIZE + 1];
	ssize_t	bytes;

	while ("reading from file descriptor")
	{
		bytes = read(fd, buffer, BUFF_SIZE);
		if (bytes == -1)
			return (-1);
		if (bytes == 0)
			return (0);
		buffer[bytes] = '\0';
		*storage = ft_strjoin_and_free(*storage, buffer, 1, 0);
		if (has_line_break(buffer))
			return (1);
	}
}

static void	extract_line_from_storage(char **storage, char **line)
{
	int		line_break_index;
	char	*temp_ptr;

	line_break_index = (int)(ft_strchr(*storage, '\n') - *storage);
	*line = ft_strsub(*storage, 0, line_break_index);
	temp_ptr = ft_strdup(*storage + line_break_index + 1);
	ft_strdel(storage);
	*storage = temp_ptr;
}

/* gnl return -1, 0 or 1 */
/* -1 on error */
/* 0 when no more lines */
/* 1 when a line is read */


int	get_next_line(int fd, char **line)
{
	static char	*storage[FD_MAX];
	int			read_status;

	read_status = 1;
	if (fd < 0 || fd >= FD_MAX || !valid_fd(fd))
		return (-1);
	if (storage[fd] == NULL || !has_line_break(storage[fd]))
		read_status = read_to_storage(fd, &storage[fd]);
	if (read_status == -1)
		return (-1);
	if (read_status == 0)
	{
		if (storage[fd][0] == '\0')
			return (0);
		else
		{
			*line = storage[fd];
			storage[fd] = NULL;
			return (1);
		}
	}
	extract_line_from_storage(&storage[fd], line);
	return (1);
}
