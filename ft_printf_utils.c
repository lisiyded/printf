/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:41:29 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:41:35 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// перевод в 16ричную систему
void	ft_putnbr(int n)
{
	unsigned int div;
	unsigned int nb;
	unsigned int abs_nb;

	div = 1;
	if (n < 0)
		abs_nb = -n;
	else
		abs_nb = n;
	nb = abs_nb;
	while (nb > 9)
	{
		div = div * 10;
		nb = nb / 10;
	}
	while (div)
	{
		ft_putchar((abs_nb / div) + '0');
		abs_nb = abs_nb % div;
		div = div / 10;
	}
}

void	ft_putnbr_u(unsigned int n)
{
	unsigned int div;
	unsigned int nb;
	unsigned int abs_nb;

	div = 1;
	abs_nb = n;
	nb = abs_nb;
	while (nb > 9)
	{
		div = div * 10;
		nb = nb / 10;
	}
	while (div)
	{
		ft_putchar((abs_nb / div) + '0');
		abs_nb = abs_nb % div;
		div = div / 10;
	}
}

void	ft_putadr(unsigned long int nb)
{
	if (nb)
	{
		ft_putstr("0x");
		ft_puthexa_ul(nb);
	}
}

void	ft_hexa_r(unsigned int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
		ft_puthexa_u(nb);
}

void	ft_puthexa_ul(unsigned long int nb)
{
	if (nb)
	{
		ft_puthexa_ul(nb / 16);
		if (nb % 16 < 10)
			ft_putnbr(nb % 16);
		else
			ft_putchar(nb % 16 + 'a' - 10);
	}
}
