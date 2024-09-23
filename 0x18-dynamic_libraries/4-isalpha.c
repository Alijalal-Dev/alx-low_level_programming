#include "main.h"
/**
 * _isalpha - checks for an alphabet character
 * @ch: the character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
