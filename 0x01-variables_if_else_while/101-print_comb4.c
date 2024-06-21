#include<stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
int n, m, q;
for (n = 48; n <= 55; n++)
{
for (m = 49; m <= 56; m++)
{
for (q = 50; q <= 57; q++)
{
if (q > m && m > n)
{
putchar(n);
putchar(m);
putchar(q);
if (n != 55 || m != 56)
{
putchar(',');
putchar(' ');
}
}
}
}
}
putchar('\n');
return (0);
}
