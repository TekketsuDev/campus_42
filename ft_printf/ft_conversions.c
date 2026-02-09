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

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
ft_putchar(va_arg(args, char));
ft_putstr(va_arg(args, char *));
ft_putptr(va_arg(args, void *));
ft_putint(va_arg(args, int));
ft_puthex(va_arg, char *)
{
	ft_putchar(HEX[c / 16]);
	ft_putchar(HEX[c % 16]);
}
