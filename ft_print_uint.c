/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:32:09 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/01 16:59:27 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (val->error != 0)
		return ;
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
