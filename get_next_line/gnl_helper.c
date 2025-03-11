/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:33:22 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 18:20:09 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

int	valid_fd(int fd)
{
	int flags;

	flags = fcntl(fd, F_GETFL);
	if (flags == -1)
		return 0;
	return (flags & O_ACCMODE) == O_RDONLY || (flags & O_ACCMODE) == O_RDWR;
}

int	get_line_break_index(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\n')
	{
		if (str[index] == '\0')
			return (-1);
		index++;
	}
	return (index);
}

static void	extract_line_from_storage_with_index(char **storage, char **line, int index)
{
	char	*temp;

	*line = ft_strsub(*storage, 0, index);
	temp = ft_strdup(*storage + index + 1);
	ft_strdel(storage);
	*storage = temp;
}

int	extract_line_from_storage(char **storage, char **line)
{
	int	index;

	index = get_line_break_index(*storage);
	if (index < 0)
		return (0);
	extract_line_from_storage_with_index(storage, line, index);
	return (1);
}
