#include "main.h"
/**
 * _printf - produces output according to format
 * @format: format string
 *
 * Return: the output asked
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;
	

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					{
						str = "(null)";
					}
				
					while (*str)
					{
						_putchar(*str);
						count++;
						str++;
					}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int n = va_arg(args, int);

				count = count + print_int(n);
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count = count + 2;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}