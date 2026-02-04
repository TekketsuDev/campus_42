/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:09:22 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/04 10:04:05 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ft_printf.h"

struct conversion { char spec;
	char base;
	char signed;
	char alphabet;
	char prefix;
}
/*
*	%c , %s char
*	%p el void * se imprime en hexadecimal
*	%d float base 10 , %u float base 10 unsigned
*	%i entero int
*	%x hexadecimal char toLowercase, %X hexadecimal char toUpperCase
*	%% print % literal
*/


[flags][width][.precision][length]specifier


int		ft_printf(char const *restrict format, ...)
{
	va_list	ap;
	int		count;
	
	va_start(ap, format);
	


}
