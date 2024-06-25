#include<unistd.h>
/**
 * _putchar - writes out a single character to stdout
 *
 * @ch: the main character to print
 *
 * Return: Always 0 (Success)
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
