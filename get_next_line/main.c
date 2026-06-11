#include "get_next_line.h"
#include <fcntl.h>
#include "../print/ft_print.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	line = NULL;
	fd = 0;
	fd2 = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		printf("START reading from file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putendl(line);
			free(line);
		}
		printf("FINISHED reading from file: %s\n", argv[1]);
		close(fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
			if (get_next_line(fd2, &line) == 1)
			{
				ft_putendl(line);
				ft_putendl("*****");
				free(line);
			}
		}
		close(fd);
		close(fd2);
	}
}