/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:00:31 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/01 14:43:27 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addlen(unsigned long num)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		ret++;
	}
	return (ret);
}

static void	ft_putadd2_pr(unsigned long int num, t_print *val)
{
	if (num >= 16)
		ft_putadd2_pr(num / 16, val);
	if (val->error != 0)
		return ;
	ft_putchar_pr("0123456789abcdef"[num % 16], val);
}

int	ft_putadd_pr(unsigned long int add, t_print *val)
{
	int	ret;

	if ((void *)add == NULL)
	{
		ft_putstr_pr("0x0", val);
		return (3);
	}
	ft_putstr_pr("0x", val);
	if (val->error != 0)
		return (0);
	ft_putadd2_pr(add, val);
	if (val->error != 0)
		return (0);
	ret = ft_addlen(add) + 2;
	return (ret);
}
