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

int _open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to) {
    *fd_from = open(file_from, O_RDONLY);
    if (*fd_from < 0) {
        dprintf(2, "Error: Can't read from file %s\n", file_from);
        return -1;
    }

    *fd_to = open(file_to, O_WRONLY | O_TRUNC);
    if (*fd_to < 0) {
        dprintf(2, "Error: Can't write to file %s\n", file_to);
        close(*fd_from);
        return -1;
    }

    return 0;
}

int _copy_data(int fd_from, int fd_to) {
    ssize_t bytes_read, bytes_written;
    char buffer[BUF_SIZE];

    do {
        bytes_read = read(fd_from, buffer, BUF_SIZE);
        if (bytes_read < 0) {
            dprintf(2, "Error: Can't read from file\n");
            return -1;
        }

        if (bytes_read == 0) {
            break;
        }

        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written < 0) {
            dprintf(2, "Error: Can't write to file\n");
            return -1;
        }

        if (bytes_written != bytes_read) {
            dprintf(2, "Error: Incomplete write\n");
            return -1;
        }
    } while (1);

    return 0;
}

int _close_files(int fd_from, int fd_to) {
    if (close(fd_from) < 0) {
        dprintf(2, "Error: Can't close fd %d\n", fd_from);
        return -1;
    }

    if (close(fd_to) < 0) {
        dprintf(2, "Error: Can't close fd %d\n", fd_to);
        return -1;
    }

    return 0;
}

int _cp(const char *file_from, const char *file_to) {
    int fd_from, fd_to;
    int result;

    result = _open_files(file_from, file_to, &fd_from, &fd_to);
    if (result < 0) {
        return result;
    }

    result = _copy_data(fd_from, fd_to);
    if (result < 0) {
        close(fd_from);
        close(fd_to);
        return result;
    }

    result = _close_files(fd_from, fd_to);
    if (result < 0) {
        return result;
    }

    return 0;
}
