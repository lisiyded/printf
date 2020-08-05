/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:39:53 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:39:58 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_x_bigx(t_list *list, unsigned int ulnb)
{
	int char_count;

	char_count = ft_length_h(ulnb);
	if (list->withprecision && list->precision == 0 && ulnb == 0)
		char_count = 0;
	if (list->width > char_count)
		char_count = list->width;
	if (list->withprecision && list->precision > char_count)
		char_count = list->precision;
	if (list->withprecision && list->precision == 0 && ulnb == 0 && list->width)
		char_count--;
	return (char_count);
}

int	ft_put_u(t_list *list, unsigned int unb)
{
	int width;
	int precision;

	precision = list->precision - ft_length_u(unb);
	if (list->index == '0' && list->withprecision)
		list->index = -1;
	if (unb == 0 && list->precision == 0 && list->withprecision)
		list->width++;
	if (precision > 0)
		width = list->width - list->precision;
	else
		width = list->width - ft_length_u(unb);
	if (list->index == '0')
		ft_write_x('0', width);
	else if (list->index == -1)
		ft_write_x(' ', width);
	if (list->withprecision)
		ft_write_x('0', precision);
	if (unb != 0 || !(list->withprecision == 1 && list->precision == 0))
		ft_putnbr_u(unb);
	if (list->index == '-')
		ft_write_x(' ', width);
	return (ft_count_u(list, unb));
}

int	ft_count_u(t_list *list, unsigned int unb)
{
	int char_count;

	char_count = ft_length_u(unb);
	if (list->width > char_count)
		char_count = list->width;
	if (list->withprecision && list->precision > char_count)
		char_count = list->precision;
	if (list->withprecision && list->precision == 0 && unb == 0 && !list->width)
		char_count = 0;
	if (list->withprecision && list->precision == 0 && unb == 0 && list->width)
		char_count--;
	return (char_count);
}

int	ft_put_p(t_list *list, unsigned long int ulnb)
{
	int length_ulnb;

	if (ulnb == 0 && list->withprecision && !list->precision)
		length_ulnb = 2;
	else if (ulnb == 0)
		length_ulnb = 3;
	else
		length_ulnb = ft_length_h(ulnb) + 2;
	if (list->index == '0')
		ft_write_x(' ', list->width - length_ulnb);
	else if (list->index == -1)
		ft_write_x(' ', list->width - length_ulnb);
	if (ulnb == 0 && list->withprecision && !list->precision)
		ft_putstr("0x");
	else if (ulnb == 0)
		ft_putstr("0x0");
	else
		ft_putadr(ulnb);
	if (list->index == '-')
		ft_write_x(' ', list->width - length_ulnb);
	if (list->width > length_ulnb)
		return (list->width);
	return (length_ulnb);
}

int	ft_putnull_c(t_list *list)
{
	if (list->index == '0' || list->index == -1)
		ft_write_x(' ', list->width - 1);
	write(1, "\x00", 1);
	if (list->index == '-')
		ft_write_x(' ', list->width - 1);
	if (list->width > 1)
		return (list->width);
	else
		return (1);
}
