#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * create_file - Creates a file.
 *
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)

{
	mode_t mode = S_IRUSR | S_IWUSR;
	FILE *file;

	if (filename == NULL)
	return (-1);

	file = fopen(filename, "w");
	if (file == NULL)
	return (-1);

	if (text_content != NULL)
	fputs(text_content, file);
	fclose(file);

	chmod(filename, mode);

	return (1);
}
