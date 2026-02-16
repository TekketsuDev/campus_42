/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:22:38 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/16 20:22:45 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_base_rec(unsigned long n, const char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (n >= (unsigned long)base_len)
		count += put_base_rec(n / (unsigned long)base_len, base);
	count += write(1, &base[n % (unsigned long)base_len], 1);
	return (count);
}

int	ft_put_c(int c)
{
	return (write(1, &c, 1));
}
