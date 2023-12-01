/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:37:09 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/01 13:01:29 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int num)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 16;
		ret++;
	}
	return (ret);
}

int	ft_puthex_pr(unsigned int num, t_print *val, const char flag)
{
	int	ret;

	ret = 0;
	if (num >= 16)
		ft_puthex_pr(num / 16, val, flag);
	if (flag == 'x')
		ft_putchar_pr("0123456789abcdef"[num % 16], val);
	else
		ft_putchar_pr("0123456789ABCDEF"[num % 16], val);
	return (ft_hexlen(num));
}
