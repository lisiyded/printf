/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:39:36 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:39:41 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_d_i(t_list *list, int nb)
{
	int width;
	int precision;
	int char_count;

	char_count = 0;
	precision = list->precision - ft_length_nb(nb);
	if (precision > 0)
		width = list->width - list->precision;
	else
		width = list->width - ft_length_nb(nb);
	if (precision > 0)
		char_count = precision;
	if (width > 0)
		char_count = char_count + width;
	char_count = char_count + ft_length_nb(nb);
	if (list->withprecision && list->precision == 0 && nb == 0 && list->width)
		char_count--;
	return (char_count);
}

int	ft_put_d_i(t_list *list, int nb)
{
	int width;
	int precision;

	if (list->index == '0' && list->withprecision)
		list->index = -1;
	if (nb < 0 && list->withprecision && list->precision)
		list->precision++;
	if (nb == 0 && list->withprecision && list->precision == 0)
		list->width++;
	precision = list->precision - ft_length_nb(nb);
	width = (precision >= 0 && list->withprecision)
		? list->width - list->precision : list->width - ft_length_nb(nb);
	if (list->index == -1)
		ft_write_x(' ', width);
	if (nb < 0)
		ft_putchar('-');
	if (list->index == '0')
		ft_write_x('0', width);
	if (list->withprecision)
		ft_write_x('0', precision);
	if (nb != 0 || !(list->withprecision == 1 && list->precision == 0))
		ft_putnbr(nb);
	if (list->index == '-')
		ft_write_x(' ', width);
	return (ft_count_d_i(list, nb));
}

int	ft_put_c(t_list *list, unsigned char c, int i)
{
	if (c == 0)
		return (ft_putnull_c(list));
	if ((list->index == '0' && i == 'c') || list->index == -1)
		ft_write_x(' ', list->width - 1);
	else if (list->index == '0' && i == '%')
		ft_write_x('0', list->width - 1);
	ft_putchar(c);
	if (list->index == '-')
		ft_write_x(' ', list->width - 1);
	if (list->width > 1)
		return (list->width);
	else
		return (1);
}

int	ft_put_s(t_list *list, char *s)
{
	int i;
	int width;

	i = 0;
	if (s == NULL)
		return (ft_put_s(list, "(null)"));
	if (ft_strlen(s) > (size_t)list->precision && list->withprecision)
		width = list->width - list->precision;
	else
		width = list->width - ft_strlen(s);
	if (width < 0)
		width = 0;
	if (list->index == '0' || list->index == -1)
		ft_write_x(' ', width);
	while (s[i] && (list->precision > i || list->withprecision == 0))
	{
		ft_putchar(s[i]);
		i++;
	}
	if (list->index == '-')
		ft_write_x(' ', width);
	return (i + width);
}

int	ft_put_x_bigx(t_list *list, unsigned int ulnb, void (*f)(unsigned int))
{
	int width;
	int precision;

	if (list->index == '0' && list->withprecision)
		list->index = -1;
	precision = list->precision - ft_length_h(ulnb);
	if (ulnb == 0 && list->precision == 0 && list->withprecision)
		list->width++;
	if (precision > 0)
		width = list->width - list->precision;
	else
		width = list->width - ft_length_h(ulnb);
	if (list->index == '0')
		ft_write_x('0', width);
	else if (list->index == -1)
		ft_write_x(' ', width);
	if (list->withprecision)
		ft_write_x('0', precision);
	if (ulnb != 0 || !(list->withprecision == 1 && list->precision == 0))
		(*f)(ulnb);
	if (list->index == '-')
		ft_write_x(' ', width);
	return (ft_count_x_bigx(list, ulnb));
}
