/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:44:02 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:44:07 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_number(const char **format, va_list ap)
{
	const char	*form;
	int			number;

	number = 0;
	form = *format;
	if (*form == '*')
	{
		number = (int)va_arg(ap, int);
		form++;
	}
	else
		while ('0' <= *form && *form <= '9')
		{
			number = number * 10 + *form - '0';
			form++;
		}
	*format = form;
	return (number);
}

int		ft_check_format(t_list *list, const char **format, va_list ap)
{
	const char	*form;
	int			c;

	form = *format;
	while (ft_flags_printf(*form, list))
		form++;
	if ((list->width = ft_check_number(&form, ap)) < 0)
	{
		list->width = -list->width;
		list->index = '-';
	}
	if (*form == '.')
	{
		form++;
		list->withprecision = 1;
	}
	if ((list->precision = ft_check_number(&form, ap)) < 0)
		list->withprecision = 0;
	*format = form;
	c = ft_convert(ap, *form, list);
	return (c);
}

int		ft_print_char(const char *format, int tt_bytes)
{
	write(1, format, 1);
	return (tt_bytes + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*list;
	int		tt_bytes;

	va_start(ap, format);
	tt_bytes = 0;
	while (*format)
	{
		if (*format != '%')
			tt_bytes = ft_print_char(format, tt_bytes);
		else
		{
			if (!(list = ft_list()))
				return (-1);
			format++;
			tt_bytes = tt_bytes + ft_check_format(list, &format, ap);
			free(list);
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (tt_bytes);
}
