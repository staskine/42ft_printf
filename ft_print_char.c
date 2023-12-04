/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:53:24 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/04 11:59:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function prints out a single character */

int	ft_putchar_pr(int c, t_print *val)
{
	if (write(1, &c, 1) == -1)
		val->error = 1;
	return (1);
}

/* This function prints out a string using ft_putchar_pr */

int	ft_putstr_pr(char *string, t_print *val)
{
	int	i;

	i = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[i] != '\0')
	{
		ft_putchar_pr(string[i], val);
		if (val->error == 1)
			break ;
		i++;
	}
	return (i);
}
