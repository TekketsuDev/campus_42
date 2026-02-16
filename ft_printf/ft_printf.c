/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:18:52 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/16 20:18:54 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_put_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_put_s(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_put_p(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_put_int(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_put_u(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_put_hex(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_put_hex(va_arg(ap, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_arg(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
