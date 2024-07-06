#include "main.h"
/**
 * set_string - function that sets the value of a pointer to a char
 * @s: pointer to the string pointer
 * @to: pointer to the new string
 */
void set_string(char **s, char *to)
{
	*s = to;
}
