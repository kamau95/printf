#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * reverse - reverses chars
 * itoa - creates buffer
 * _printf - custom printf
 * main - entry
 * Return - zero for success
 * itoa - function to handle integer
 * @str: string pointer
 * @length - of a string
 */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

while (start < end)
{
	char temp = str[start];

	str[start] = str[end];
	str[end] = temp;
	start++;
	end--;
}
}

char *itoa(int num)
{
	static char buffer[20];
	int i = 0;
	int isNegative = 0;

	if (num == 0)
	{
	buffer[i++] = '0';
	buffer[i] = '\0';

	return (buffer);
	}
	if (num < 0)
	{
	isNegative = 1;
	num = -num;
	}
	while (num != 0)
	{
	int rem = num % 10;

	buffer[i++] = rem + '0';
	num = num / 10;
	}

	if (isNegative)
	{
	buffer[i++] = '-';
	}
	buffer[i] = '\0';
	reverse(buffer, i);

	return (buffer);
}

int _printf(const char *format, ...)
{
int printed = 0;

va_list args;
if (format == NULL)
{
	return (-1);
}

va_start(args, format);
while (*format)
{
if (*format != '%')
{
	write(1, format, 1);
}

else
{
format++;
if (format == NULL)
{
	break;
}

if (*format == 'c')
{
	char my_char = va_arg(args, int);

	write(1, &my_char, 1);
	printed++;
}
else if (*format == '%')
{
	write(1, format, 1);
	printed++;
}
else if (*format == 'd' || *format == 'i')
{
	int value = va_arg(args, int);
	char *int_str = itoa(value);
	int i = 0;

	while (int_str[i] != '\0')
	{
	write(1, &int_str[i], 1);
	i++;
	printed++;

	}
}
else if (*format == 's')
{
	char *str = va_arg(args, char*);
	int str_length = 0;

	while (str[str_length] != '\0')
	{
	write(1, str, str_length);
	printed += str_length;
	}
}
}
format++;
}
va_end(args);
return (printed);
}
int main(void)
{
_printf("leopa\n");
_printf("%c\n", 'v');
_printf("%%\n");
_printf("%d\n", 23);
return (0);
}
