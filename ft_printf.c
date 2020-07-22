#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
void ft_printf(const char *format, ...)
{
	va_list		ap;
	char *name;
	va_start(ap, format);

	name = va_arg(ap, char*);
	ft_putstr(name);
	va_end(ap);
}

int main (void)
{
char *str;
*str = "stroka";
ft_printf("%s\n", str);

}
