#ifdef FT_PRINTF.H
	
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
# include <stddef.h>
# include <stdint.h>

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
	int		precision;  /* -1 if not present, >=0 when '.' present */
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


#endif // FT_PRINTF.H
