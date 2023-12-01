/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:40:40 by sataskin          #+#    #+#             */
/*   Updated: 2023/11/30 15:13:11 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	int		error;
	int		ret;	
}				t_print;

int	ft_printf(const char *string, ...);
int	ft_putchar_pr(int c, t_print *val);
int	ft_putstr_pr(char *string, t_print *val);
int	ft_putint_pr(int n, t_print *val);
int	ft_putuint_pr(int num, t_print *val);

#endif