/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:21:52 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/14 16:50:57 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_form
{
	int		minus;      /* '-' */
	int		zero;       /* '0' */
	int		hash;       /* '#' */
	int		plus;       /* '+' */
	int		space;      /* ' ' */
	int		width;      /* field minimum width */
	int		precision;  /* -1 if not present */
	char	spec;       /* c s p d i u x X % */
}	t_form;

int		ft_printf(const char *format, ...);

/*
** ==============================
** PARSING
** ==============================
*/

void		init_flag_eval(t_form *flags);
int			is_spec(char c);
int			is_flag(char c);

const char	*eval_flags(t_form *t, const char *format);
const char	*eval_width(t_form *t, const char *format);
const char	*eval_precision(t_form *t, const char *format);

/*
** ==============================
** DISPATCH
** ==============================
*/

int			print_arg(t_form *t, va_list ap);

/*
** ==============================
** CONVERSIONS
** ==============================
*/

int			ft_put_c(t_form *t, va_list ap);
int			ft_put_s(t_form *t, va_list ap);
int			ft_put_p(t_form *t, va_list ap);
int			ft_put_int(t_form *t, va_list ap);
int			ft_put_u(t_form *t, va_list ap);
int			ft_put_hex(t_form *t, va_list ap);
int			put_hex_rec(uintptr_t n, const char *digits);

void		ft_putchar(char c);
void		ft_putstr(char *str);

#endif /* FT_PRINTF_H */

