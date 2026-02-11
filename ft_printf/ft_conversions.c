/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:03:24 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/09 21:22:47 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1,c,1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
ft_putchar(va_arg(args, char));
ft_putstr(va_arg(args, char *));
ft_putptr(va_arg(args, void *));
ft_putint(va_arg(args, int));

ft_put_hex(t_form *t, va_list arg)
{
	if(t->spec == 'p' || (t->spec == 'x' && t->hash))
	{

	}
	else if (t->spec == 'x')
	{

	}
	else
	{
		//X 
	}
	ft_putchar(HEX[c / 16]);
	ft_putchar(HEX[c % 16]);
}

