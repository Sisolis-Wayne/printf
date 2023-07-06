#include "main.h"

/**
 * _printf - a function that produces output according to format
 * @format: string pointer
 * Return: 0 if success
 */

int _printf(const char *format, ...)
{
	unsigned int x;
	va_list all;
	char *s;
	char c;
	size_t len;

	va_start(all, format);

	x = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			switch (format[++x])
			{
				case 'c':
					c = va_arg(all, int);
					_putchar(c);
					break;
				case 's':
					s = va_arg(all, char *);
					if (s == NULL)
						s = "(nil)";
					len = strlen(s);

					write(1, s, len);
					break;
				case '%':
					_putchar('%');
					break;
				default:
					x++;
					break;
			}
		}
		else
			_putchar(format[x]);

		x++;
	}
	va_end(all);

	return (0);
}
