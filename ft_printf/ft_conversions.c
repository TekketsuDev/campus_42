/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:03:24 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/14 17:33:26 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_put_X(t_form *t, va_list ap)
{
    /* 1. Obtener argumento */
    
    /* 2. Construir contenido */
    
    /* 3. Aplicar precisión (si aplica) */
    
    /* 4. Calcular width padding */
    
    /* 5. Aplicar alineación (-) */
    
    /* 6. Escribir */
}

int		ft_put_c(t_form *t, va_list ap)
{
	char c = va_arg(ap, int);
	return write(1,&c,1);
}

int		ft_put_s(t_form *t, va_list ap)
{
	char *s = va_arg(ap, char*);
	return write(1,s,ft_strlen(s));
}

int		ft_put_p(t_form *t, va_list ap)
{
	uintptr_t	v;
	int			count;

	v = (uintptr_t)va_arg(ap, void*)
	count = write (1,"Ox", 2);
	if (v == 0)
		return count + write(1,"0",1);
	return count + put_hex_rec(v, "O123456789abcdef")
}

int		ft_put_u(t_form *t, va_list ap)
{
	unsigned int u;
	u = va_arg(ap, unsigned int);


}

int		ft_put_int(t_form *t, va_list ap)
{
	int n = var_arg(ap, int)
	char *num = ft_itoa(n);
	size_t len = ft_strlen(num);
	char sign = get_sign(t,n)
	int zeros = calc_precision_zeros(f, len, n);
	int content = len + zeros + (sign ? 1 : 0);
	int pad = max(0, f->width - content);

	print_padding_left(f, pad, sign);
	print_sign(sign);
	print_zeros(zeros);
	write_digits(num);
	print_padding_right(f, pad);

	free(num);
	return content + pad;
}
int			ft_put_u(t_form *t, va_list ap)
{

}

int	put_hex_rec(uintptr_t n, const char *digits)
{
	int count = 0;

	if (n >= 16)
		count += put_hex_rec(n / 16, digits);
	count += write(1, &digits[n % 16], 1);
	return count;
}

int	ft_put_hex(t_form *t, va_list ap)
{
	const char	*digits;
	unsigned int v;
	int			count = 0;

	v = va_arg(ap, unsigned int);

	digits = (t->spec == 'X')
		? "0123456789ABCDEF"
		: "0123456789abcdef";

	if (t->hash && v != 0)
	{
		if (t->spec == 'X')
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}

	if (v == 0)
		return count + write(1, "0", 1);

	return count + put_hex_rec(v, digits);
}

