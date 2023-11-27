#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * _cp - Copies the content of a file to another file.
 *
 * @file_from: The name of the file to copy from.
 * @file_to: The name of the file to copy to.
 *
 * Return: 0 on success, or -1 on error.
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	if (argc != 3) 
	{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_TRUNC);
	if (fd_to < 0)
	{
	dprintf(2, "Error: Can't write to file %s\n", argv[2]);
	exit(99);
	}

	do
	{
	bytes_read = read(fd_from, buffer, BUF_SIZE);
	if (bytes_read < 0)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}

	if (bytes_read == 0)
	{
	break;
	}

	bytes_written = write(fd_to, buffer, bytes_read);
	if (bytes_written < 0)
	{
	dprintf(2, "Error: Can't write to file %s\n", argv[2]);
	exit(99);
	}

	if (bytes_written != bytes_read)
	{
	dprintf(2, "Error: Incomplete write\n");
	exit(99);
	}
	} while (1);

	if (close(fd_from) < 0)
	{
	dprintf(2, "Error: Can't close fd %d\n", fd_from);
	exit(100);
	}

	if (close(fd_to) < 0)
	{
	dprintf(2, "Error: Can't close fd %d\n", fd_to);
	exit(100);
	}

	exit(0);
}
