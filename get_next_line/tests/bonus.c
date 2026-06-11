#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "../get_next_line.h"

static int	g_test = 1;

static void	sigsegv_handler(int sig)
{
	(void)sig;
	printf("\033[31m[SIGSEGV]\033[0m\n");
	exit(1);
}

static void	title(const char *str)
{
	g_test = 1;
	printf("\033[34m%s\033[0m\n", str);
}

static void	show_leaks(void)
{
	printf("\n");
}

static void	gnl(int fd, const char *expected)
{
	char	*line;
	int		ret;
	int		pass;
	size_t	len;
	char	*stripped;

	line = NULL;
	ret = get_next_line(fd, &line);
	if (expected == NULL)
	{
		pass = (ret == -1) || (ret == 0 && (line == NULL || line[0] == '\0'));
		printf("[%02d] %s (ret=%d)\n", g_test,
			pass ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m", ret);
	}
	else
	{
		len = strlen(expected);
		if (len > 0 && expected[len - 1] == '\n')
		{
			stripped = malloc(len);
			if (!stripped)
				return ;
			memcpy(stripped, expected, len - 1);
			stripped[len - 1] = '\0';
			pass = (ret == 1 && line != NULL && strcmp(line, stripped) == 0);
			free(stripped);
		}
		else
		{
			pass = (ret == 0 && line != NULL && strcmp(line, expected) == 0);
		}
		if (pass)
			printf("[%02d] \033[32mOK\033[0m\n", g_test);
		else
			printf("[%02d] \033[31mKO\033[0m (ret=%d, got='%s', expected='%s')\n",
				g_test, ret, line ? line : "(null)", expected);
	}
	free(line);
	g_test++;
}

int	main(void)
{
	int	fd[4];

	signal(SIGSEGV, sigsegv_handler);
	title("multiple fd: ");

	fd[0] = open("files/41_with_nl", O_RDONLY);
	gnl(1000, NULL);
	gnl(fd[0], "0123456789012345678901234567890123456789\n");

	fd[1] = open("files/42_with_nl", O_RDONLY);
	gnl(1001, NULL);
	gnl(fd[1], "01234567890123456789012345678901234567890\n");

	fd[2] = open("files/43_with_nl", O_RDONLY);
	gnl(1002, NULL);
	gnl(fd[2], "012345678901234567890123456789012345678901\n");

	gnl(1003, NULL);
	gnl(fd[0], "0");

	gnl(1004, NULL);
	gnl(fd[1], "1");

	gnl(1005, NULL);
	gnl(fd[2], "2");

	gnl(fd[0], NULL);
	gnl(fd[1], NULL);
	gnl(fd[2], NULL);
	show_leaks();

	fd[3] = open("files/nl", O_RDONLY);
	gnl(1006, NULL);
	gnl(fd[3], "\n");
	gnl(1007, NULL);
	gnl(fd[3], NULL);
	show_leaks();

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	write(1, "\n", 1);
	return (0);
}
