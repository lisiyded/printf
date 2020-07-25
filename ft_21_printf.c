#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar (char c)
{
    write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int i;
    i = 0;
    
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    return(i);
}

void    ft_putnbr(int nb)
{
    long long n_nb;

    n_nb = nb;
    if (n_nb < 0)
    {
        ft_putchar('-');
        n_nb = n_nb * -1;
    }
    if (n_nb >= 10)
    {
        ft_putnbr(n_nb / 10);
        ft_putnbr(n_nb % 10);
    }
    else
        ft_putchar(n_nb + '0');
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;
	int 		i;
    char letter;
    int letter_u;
    int letter_i;
    int letter_d;
    int letter_p;
    
    
	count = 0;
	i = 0;

	va_start(ap, str);
		
	while (str[i])
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{
				ft_putchar ('%');
				i = i + 2;
				count++;
			}
			else if (str[i] == '%')
			{
				while (str[i] && (str[i] !=  'c' && str[i] != 's' && str[i] != 'u' && str[i] != 'i' && str[i] != 'd' && str[i] != 'p')) // check c, s, p, d, i, x, X
					{
						i++;
					}
                if (str[i] == 'c')
                {
                    letter = va_arg(ap, int);
                    ft_putchar(letter);
                    i++;
                    count++;
                }
                
                else if (str[i] == 's')
                {
                    count += ft_putstr(va_arg(ap, char*));
                    i++;
                }
                
                else if (str[i] == 'u')
                {
                    letter_u = va_arg(ap,unsigned int);
                    ft_putnbr(letter_u);
                    i++;
                    count++;
                }
                
                else if (str[i] == 'i')
                {
                    letter_i = va_arg(ap,unsigned int);
                    ft_putnbr(letter_i);
                    i++;
                    count++;
                }
            else if (str[i] == 'd')
            {
                letter_d = va_arg(ap, unsigned int);
                ft_putnbr(letter_d);
                i++;
                count++;
            }
           // else if (str[i] == 'p')
           // {
           //     letter_p = va_arg(ap, int);
            //
           // }
                
            else if (str[i] == 'x')
            {
                
            }
            // else if (str[i] == 'X')
			// flag - 0 . *	
			}
			else 
			{
				ft_putchar(str[i]);
                i++;
				count++;
			}

		}
	va_end(ap);
	return (count);
}
int main (void)
{
    int a = 10;
    int *b = &a;
    
   // ft_printf("TEST ft_printf line is %c %c %c %%c %s %u %i %d %p \n", 't', 'o', 'y', "stroka", 555777, 8888, 9999, 0 );
 // printf("____printf line is %c %c %c %%c %s %u %i %p %x\n", 't', 'o', 'y', "stroka", 555777, 8, &b, b);
    printf("%p\n", b);
    printf("b=%[X]\n", b);
    return (0);
}
