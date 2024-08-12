#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define UNREAD "Error: Can't read from file %s\n"
#define UNCREATE "Error: Can't write to %s\n"
#define UNCLOSED "Error: Can't close fd %d\n"

/**
 * main - entry pointe
 * @ac: arguments count
 * @av: arguments vectors
 * Return: 1 (Success)
 */
int main(int ac, char **av)
{
	int file_from = 0, file_to = 0;
	ssize_t bytes;
	char buff[BUFF_SIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, UNREAD, av[1]), exit(98);
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, UNCREATE, av[2]), exit(99);
	while ((bytes = read(file_from, buff, BUFF_SIZE)) > 0)
		if (write(file_to, buff, bytes) != bytes)
			dprintf(STDERR_FILENO, UNCREATE, av[2]), exit(99);
	if (bytes == -1)
		dprintf(STDERR_FILENO, UNREAD, av[1]), exit(98);
	file_from = close(file_from);
	file_to = close(file_to);
	if (file_from)
		dprintf(STDERR_FILENO, UNCLOSED, file_from), exit(100);
	if (file_to)
		dprintf(STDERR_FILENO, UNCLOSED, file_to), exit(100);
	return (EXIT_SUCCESS);
}
