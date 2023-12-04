/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:00:31 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/04 12:01:41 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function finds out the length of the hexadecimal and 2 length for the 
0x is added manually */

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

/* This function prints out the hexadecimal using recursion */

static void	ft_putadd2_pr(unsigned long int num, t_print *val)
{
	if (num >= 16)
		ft_putadd2_pr(num / 16, val);
	if (val->error != 0)
		return ;
	ft_putchar_pr("0123456789abcdef"[num % 16], val);
}

/* This function handles null pointers and adds the 0x and then
hands the rest to the next printer function */
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
