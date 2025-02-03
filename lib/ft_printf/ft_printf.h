/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsen <emsen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:25 by emsen             #+#    #+#             */
/*   Updated: 2023/12/29 20:25:39 by emsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_putnbrhexl(unsigned int n);
int		ft_putnbrhexb(unsigned int n);
int		ft_putnbrhexllong(unsigned long n);
int		ft_putnbrhexp(unsigned long n);
int		counter(int *a, int b);
void	ft_printfif(va_list *ap, int i, int *count, const char *a);
int		ft_printf(const char *a, ...);

#endif