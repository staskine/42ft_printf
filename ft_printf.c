/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:27 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/04 11:55:20 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This is where the function finds out the conversion it needs to handle
c = print out a character
s = print out a string
p = prints out a void pointer argument in hexadecimal form
i & d = prints out a base 10 integer
u = print out an unsigned integer (base 10)
X = print out a number in hexadecimal (base 16) in uppercase format
x = print out a number in hexadecimal (base 16) in lowercase format
% = print out a percent sign 
*/

static int	check_conv(va_list ap, const char c, t_print *val)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar_pr(va_arg(ap, int), val);
	else if (c == 's')
		ret += ft_putstr_pr(va_arg(ap, char *), val);
	else if (c == 'p')
		ret += ft_putadd_pr(va_arg(ap, unsigned long int), val);
	else if (c == 'i' || c == 'd')
		ret += ft_putint_pr(va_arg(ap, int), val);
	else if (c == 'u')
		ret += ft_putuint_pr(va_arg(ap, int), val);
	else if (c == 'X' || c == 'x')
		ret += ft_puthex_pr(va_arg(ap, unsigned int), val, c);
	else if (c == '%')
	{
		if (write(1, "%", 1) == -1)
			val->error = 1;
		return (1);
	}
	return (ret);
}

/* The main function for my ft_printf. It takes the argument from 
the input and goes through the string till it finds a conversion. Then
it acts the same way as the original printf. This function returns the 
value of characters it has printed out. */
 
int	ft_printf(const char *str, ...)
{
	t_print	val;
	va_list	ap;
	int		i;

	val.ret = 0;
	val.error = 0;
	va_start(ap, str);
	i = 0;
	while (str[i] != '\0' && val.error == 0)
	{
		if (str[i] == '%')
		{
			val.ret += check_conv(ap, str[i + 1], &val);
			i++;
		}
		else
			val.ret += ft_putchar_pr(str[i], &val);
		i++;
	}
	va_end(ap);
	if (val.error != 0)
		return (-1);
	return (val.ret);
}
