/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:23:33 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/14 16:40:33 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ft_printf.h"

void  init_flag_eval (t_form *flags)
{
    flags->minus = 0;
    flags->zero = 0;
    flags->width = 0;
    flags->hash = 0;
    flags->plus = 0;
    flags->space = 0;
    //flags->precision = -1;
    flags->spec = 0;
}

int   is_spec(char c)
{
  return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
  c == 'u' ||c == 'x' ||c == 'X' || c == '%');
}

int is_flag(char c)
{
    return (c=='-' || c=='0' || c=='#' || c=='+' || c==' ');
}

const char *eval_flags (t_form *t, const char *format)
{
  while(is_flag(*format))
  {
    if (*format == '0')
      t->zero = 1;
    else if (*format == '-')
      t->minus = 1;
    else if (*format == '+')
      t->plus = 1;
    else if (*format == ' ')
      t->space = 1;
    else if (*format == '#')
      t->hash = 1;
    format++;
  }
  //To contrarrest contrary effects after reading all flags
  if (t->minus)
    t->zero = 0;
  if (t->plus)
    t->space = 0;
  return (format);
}

const char *eval_width (t_form *t, const char *format)
{
  	while ( *format >= '0' && *format <= '9')
	{
		t->width = t->width * 10 + (*format - '0');
		format++;
	}
	return (format);
}

const char *eval_precision(t_form *t, const char *format)
{
	if (*format == '.'){
		format++;
	}
	while (*format >= '0' && *format <= '9' && t->precision != -1)
	{
		t->precision = t->precision * 10 + (*format - '0');
		format++;
	}
	return (format);
}

char const *resolve_flags(t_form *t,args){
  char * construct;
  while(t->precision !=0 && strlen(args) )
  {
    t->precision--;
  }
  if (t->width)
}

const  *print_arg(t_form *t, va_list ap)
{
  switch (t->spec) {
    case 'c':
		return ft_put_c(t, ap);
	case 's':
		return ft_put_s(t, ap)
	case 'p':
		return ft_put_p(t, ap);
	case 'd':
	case 'i':
		return ft_put_int(t, ap);
	case 'u': 
		return ft_put_u(t, ap);
	case 'x':
	case 'X':
		return ft_put_hex(t, ap);
    case '%':
		return write(1,'%',1);
    break;
    case default:
      write(1, "Error",5);
  }
}

int main(void)
{
  int count = 0;
  char * otra = "hola"
  const char *format = "holaaaa", otra, count;
	va_list args;
	va_start(args, format);
	t_form forma;
	while (*format) {
    if (*format == '%')
    {
      format++;
      //Remember that we return the last pointer address to evaluate the other things
      init_flag_eval(&forma);
      format = eval_flags(&forma, format);
      format = eval_width(&forma, format);
       if (is_spec(*format))
      {
         forma.spec = *format;
         format++;
		 count += print_arg(&forma, args);
      }
    }
    else{
      write(1,format++,1);
	  format++;
    }
  }
  return (0);
}
