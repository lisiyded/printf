/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:40:15 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:40:20 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_printf(char c, t_list *list)
{
	if (c == '-') // если поступил минус 
	{
		list->index = '-';
		return (1);
	}
	if (c == '0' && list->index != '-') //если поступил нуль
	{
		if (list->index != '-')
			list->index = '0';
		return (1);
	}
	return (0);
}

// - выводимое значение выравнивается по левому краю в пределах минимальной ширины поля / нет по правому
// * ширина  
//  
