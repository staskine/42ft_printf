/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:55 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/04 11:56:28 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function finds out the length of the number */

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648 || n == 2147483647)
	{
		if (n < 0)
			return (11);
		return (10);
	}
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

/* This function prints out a number using recursion */

int	ft_putint_pr(int n, t_print *val)
{
	int	ret;

	ret = ft_intlen(n);
	if (n == -2147483648)
	{
		ft_putstr_pr("-2147483648", val);
		if (val->error != 0)
			return (0);
	}
	else if (n < 0)
	{
		ft_putchar_pr('-', val);
		if (val->error != 0)
			return (0);
		ft_putint_pr(-n, val);
	}
	else
	{
		if (n > 9)
			ft_putint_pr((n / 10), val);
		if (val->error != 0)
			return (0);
		ft_putchar_pr((n % 10) + '0', val);
	}
	return (ret);
}
