#ifdef FT_PRINTF.H
	
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#define HEX "0123456789abcdef"
/*
** Format state (mandatory + bonus-ready)
*/
typedef struct s_form
{
	int		minus;      /* '-' */
	int		zero;       /* '0' */
	int		hash;       /* '#' */
	int		plus;       /* '+' */
	int		space;      /* ' ' */
	int		width;      /* field minimum width */
	//int		 precision;  /* -1 if not present, >=0 when '.' present */
	char	spec;       /* c s p d i u x X % */
}	t_form;

/*
** Public API
*/
int			ft_printf(char const *format, ...);

void		init_flag_eval(t_form *flags);
int			is_spec(char c);
int			is_flag(char c);
char const	*eval_flags(t_form *t, char const *format);
char const	*eval_width(t_form *t, char const *format);
char const	*eval_precision(t_form *t, char const *format);
char const  *resolve_spec(t_form *t, va_arg *args);
char const  *print_arg(t_form *t, va_arg *args);
ft_putchar(va_arg(args, char));
ft_putstr(va_arg(args, char *));
ft_putptr(va_arg(args, void *));
ft_putint(va_arg(args, int));
ft_puthexa(va_arg, char *);

#endif // FT_PRINTF.H
