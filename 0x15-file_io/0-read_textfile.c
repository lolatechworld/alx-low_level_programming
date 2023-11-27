#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t bytes_read = 0;
    ssize_t bytes_to_read = letters;
    FILE *file;
    char buffer[BUFSIZ];

    if (filename == NULL) {
        return 0;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    while (bytes_to_read > 0) {
        size_t bytes_actually_read = fread(buffer, 1, sizeof(buffer), file);
        if (bytes_actually_read == 0) {
            break;
        }

        if (fwrite(buffer, 1, bytes_actually_read, stdout) != bytes_actually_read) {
            fclose(file);
            return 0;
        }

        bytes_read += bytes_actually_read;
        bytes_to_read -= bytes_actually_read;
    }

    fclose(file);

    return bytes_read;
}
