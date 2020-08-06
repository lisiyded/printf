/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:39:06 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:39:11 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// конвертация и печать для типов символ строка 
//  d i знаковое десятичное
int	ft_convert(va_list ap, char c, t_list *list)
{
	char	letter;
	char	*str;
	int		nb;

	if (c == 'c')
	{
		letter = (int)va_arg(ap, int);
		return (ft_put_c(list, letter, 'c'));
	}
	else if (c == 's')
	{
		str = (char *)va_arg(ap, char *);
		return (ft_put_s(list, str));
	}
	else if (c == 'd' || c == 'i')
	{
		nb = (int)va_arg(ap, int);
		return (ft_put_d_i(list, nb));
	}
	else
		return (ft_convert_type(ap, c, list));
}

int	ft_convert_type(va_list ap, char c, t_list *list)
{
	unsigned long int	ulnb;
	unsigned int		unb;

	if (c == 'p')
	{
		ulnb = (unsigned long int)va_arg(ap, unsigned long int);
		return (ft_put_p(list, ulnb));
	}
	else if (c == 'x')
	{
		unb = (unsigned long int)va_arg(ap, unsigned int);
		return (ft_put_x_bigx(list, unb, ft_hexa_r));
	}
	else if (c == 'X')
	{
		unb = (unsigned long int)va_arg(ap, unsigned int);
		return (ft_put_x_bigx(list, unb, ft_hexa_mr));
	}
	else
		return (ft_convertion(ap, c, list));
	return (0);
}

// u десятичное беззнаковое
int	ft_convertion(va_list ap, char c, t_list *list)
{
	unsigned int	unb;
	char			letter;

	if (c == 'u')
	{
		unb = (unsigned int)va_arg(ap, unsigned int);
		return (ft_put_u(list, unb));
	}
	else if (c == '%')
	{
		letter = '%';
		return (ft_put_c(list, letter, '%'));
	}
	else
		return (0);
}
