#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int create_file(const char *filename, char *text_content)
{
    mode_t mode = S_IRUSR | S_IWUSR;
    FILE *file;

    if (filename == NULL) {
        return -1;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }

    if (text_content != NULL) {
        fputs(text_content, file);
    }

    fclose(file);

    chmod(filename, mode);

    return 1;
}
