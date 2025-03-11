/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:54:57 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 18:26:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "gnl_helper.h"
#include "../utility/ft_utility.h"

static int storage_expand(int fd, char **storage)
{
	char    buffer[BUFF_SIZE + 1];
	ssize_t bytes;

	while (1)
	{
		bytes = read(fd, buffer, BUFF_SIZE);
		if (bytes < 0)
			return (-1);
		if (bytes == 0)
			return (0);
		buffer[bytes] = '\0';
		*storage = ft_strjoin_and_free(*storage, buffer, 1, 0);
		if (get_line_break_index(buffer) >= 0)
			return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*storage[FD_MAX];
	int		res;

	if (fd < 0 || fd > FD_MAX || !valid_fd(fd))
		return (-1);
	if (storage[fd] != NULL && extract_line_from_storage(&storage[fd], line))
		return (1);
	res = storage_expand(fd, &storage[fd]);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		*line = storage[fd];
		storage[fd] = NULL;
		return (0);
	}
	extract_line_from_storage(&storage[fd], line);
	return (1);
}
