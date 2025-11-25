#include "main.h"

/**
 * print_int_recursive - prints a positive number recursively
 * @num: positive number
 *
 * Return: number of characters printed
 */
static int print_int_recursive(long num)
{
	int count = 0;

	if (num / 10)
	{
		count = count + print_int_recursive(num / 10);
	}

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * print_int - prints an integer and returns the number of chars
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	long num = n;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	count = count + print_int_recursive(num);

	return (count);
}
