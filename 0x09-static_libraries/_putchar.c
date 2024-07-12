#include <unistd.h>
/**
 * _putchar - prints the character ch to stdout
 * @ch: the character to print
 * Return: Always 1 (Success)
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
