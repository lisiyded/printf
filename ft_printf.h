/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:41:07 by spowers           #+#    #+#             */
/*   Updated: 2020/08/05 21:41:12 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	int				index;
	int				width;
	int				withprecision;
	int				precision;
}					t_list;

int					ft_length_h(unsigned long	int	nb);
int					ft_put_c(t_list *list, unsigned char c, int i);
int					ft_put_s(t_list *list, char *s);
int					ft_putnull_c(t_list *list);
int					ft_length_nb(int nb);
int					ft_length_u(unsigned int ui);
size_t				ft_strlen(const char *s);
void				ft_write_x(char c, int x);
t_list				*ft_list(void);
int					ft_flags_printf(char c, t_list *list);
void				ft_putnbr(int nb);
void				ft_putnbr_u(unsigned int nb);
void				ft_putchar(char s);
void				ft_puthexa_u(unsigned int nb);
void				ft_puthexa_um(unsigned int nb);
int					ft_convert(va_list lst_format, char c, t_list *list);
int					ft_convert_type(va_list lst_format, char c, t_list *list);
void				ft_putstr(char *s);
void				ft_putadr(unsigned long int nb);
void				ft_hexa_mr(unsigned int nb);
void				ft_hexa_r(unsigned int nb);
int					ft_put_d_i(t_list *list, int nb);
int					ft_put_x_bigx(t_list *list, unsigned int ulnb,
										void (*f)(unsigned int));
int					ft_count_x_bigx(t_list *list, unsigned int ulnb);
int					ft_put_u(t_list *list, unsigned int unb);
int					ft_count_u(t_list *list, unsigned int unb);
int					ft_put_p(t_list *list, unsigned long int ulnb);
int					ft_convertion(va_list lst_format, char c, t_list *list);
int					ft_printf(const char *format, ...);
int					ft_print_char(const char *format, int tt_bytes);
int					ft_check_format(t_list *list,
										const char **format, va_list ap);
int					ft_check_number(const char **format, va_list ap);
void				ft_puthexa_ul(unsigned long int nb);

#endif
