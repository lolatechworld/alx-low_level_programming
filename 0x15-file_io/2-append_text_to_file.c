#include <stdio.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 *
 * @filename: The name of the file to append to.
 * @text_content: The NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 * Do not create the file if it does not exist
 * If filename is NULL return -1
 * If text_content is NULL, do not add anything to the file.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;

	if (filename == NULL)
	return (-1);

	file = fopen(filename, "a");
	if (file == NULL)
	return (-1);

	if (text_content != NULL)
	fputs(text_content, file);

	fclose(file);

	return (1);
}
