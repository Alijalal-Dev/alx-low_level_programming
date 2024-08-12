#include "main.h"

/**
 * _strlen - Function to calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}


/**
 * create_file - Creates a file and writes text to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes = 0, ctn_len = _strlen(text_content);

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);
	if (ctn_len)
		bytes = write(file_descriptor, text_content, ctn_len);
	close(file_descriptor);
	return (bytes == ctn_len ? 1 : -1);
}
