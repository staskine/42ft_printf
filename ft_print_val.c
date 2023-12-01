/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:55 by sataskin          #+#    #+#             */
/*   Updated: 2023/11/30 16:28:39 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putint_pr(int n, t_print *val)
{
	int	ret;

	ret = ft_intlen(n);
	if (n == -2147483648)
	{
		ft_putchar_pr('-', val);
		ft_putchar_pr('2', val);
		ft_putint_pr(147483648, val);
	}
	else if (n < 0)
	{
		ft_putchar_pr('-', val);
		ft_putint_pr(-n, val);
	}
	else
	{
		if (n > 9)
			ft_putint_pr((n / 10), val);
		ft_putchar_pr((n % 10) + '0', val);
	}
	return (ret);
}

static int	ft_intlen_uint(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static void	ft_putunint_pr(unsigned int n, t_print *val)
{
	if (n > 9)
		ft_putunint_pr((n / 10), val);
	ft_putchar_pr((n % 10) + '0', val);
}

int	ft_putuint_pr(int num, t_print *val)
{
	int		ret;
	size_t	value;

	value = 0 - 1;
	if (num < 0)
		num = value + num + 1;
	ret = ft_intlen_uint(num);
	ft_putunint_pr((unsigned int)num, val);
	return (ret);
}
