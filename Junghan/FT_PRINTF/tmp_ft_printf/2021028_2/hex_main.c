#include <stdio.h>
#include <stdarg.h>

int ff_printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	printf("%u",va_arg(ap, unsigned int));
	va_end(ap);
	
	return (count);
}

int main()
{
	unsigned int a;
	a = 20;
	ff_printf("asdf",&a);
}

