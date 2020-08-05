/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:41:48 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:41:53 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length_h(size_t nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int		ft_length_u(unsigned int ui)
{
	int i;

	i = 0;
	if (ui == 0)
		return (1);
	while (ui)
	{
		i++;
		ui = ui / 10;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (-1);
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
