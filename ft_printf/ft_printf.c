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

//#inlcude "ft_printf.h"
/*
*	%c , %s char
*	%p el void * se imprime en hexadecimal
*	%d float base 10 , %u float base 10 unsigned
*	%i entero int
*	%x hexadecimal char toLowercase, %X hexadecimal char toUpperCase
*	%% print % literal

 *
 * The field width

An optional decimal digit string (with nonzero first digit) specifying a minimum field width.
If the converted value has fewer characters than the field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been given). 
Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th argument, respectively, which must be of type int.
A negative field width is taken as a '-' flag followed by a positive field width. 
In no case does a nonexistent or small field width cause truncation of a field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.


* Flags:
* "-" -> The converted value is to be left adjusted on the field boundary.
* (The default is right justification.) Except for n conversions, the converted value is padded on the right with blanks, rather than on the left with blanks or zeros.
* A - overrides a 0 if both are given.
*
* "0" -> The value should be zero padded. For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted value is padded on the left with zeros rather than blanks. 
* If the 0 and - flags both appear, the 0 flag is ignored.* If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored. For other conversions, the behavior is undefined.
*
* "#" -> The value should be converted to an "alternate form". For o conversions, the first character of the output string is made zero (by prefixing a 0 if it was not zero already).
* For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it. For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows).
* For g and G conversions, trailing zeros are not removed from the result as they would otherwise be.
* For other conversions, the result is undefined.
*
* " " -> A blank should be left before a positive number (or empty string) produced by a signed conversion.
*
* "+" -> A sign (+ or -) should always be placed before a number produced by a signed conversion.
* By default a sign is used only for negative numbers. A + overrides a space if both are used. 
 [flags][width][.precision][length]specifier */

<<<<<<< HEAD
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#inlcude "ft_printf.h"

typedef struct s_form
{
  //c, s, p, d, i, x, X, % 
	int minus;      // '-'
	int zero;       // '0'
	int hash;       // '#'
	int plus;       // '+'
	int space;      // ' '
	int width;      // field width
	int precision;  // -1 if not present (bonus with '.')
	char spec;      // conversion: c s p d i u x X %
}	t_form;

typedef struct s_form_node
{
	s_form current;
	struct s_form_node *next;
}	t_form_node;


void  init_flag_eval (t_form *flags)
{
    flags->minus = 0;
    flags->zero = 0;
    flags->width = 0;
    flags->hash = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->precision = -1;
    flags->spec = 0;
}
/*
int		ft_printf(char const *restrict format, ...)
{
	va_list	ap;
	
	va_start(ap, format);
	va_arg();
	va_end();
}
*/
//%-05d → flags: -,0 → width: 5 → zero ignorado
//pointer → "A %d B %x C %s\n"
//arguments   → [10][255]["hi"]

int   is_spec(char c)
{
  return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
  c == 'u' ||c == 'x' ||c == 'X' || c == '%');
}
static int is_flag(char c)
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


//[flags][width][.precision][length][specifier]

int main(void)
{
  const char *format = "Maia es %muy guapa%0500s";

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
      }
    }
    else{
      write(1,format++,1);
	  format++;
    }
  }
  /*
  char c = 'a';
  printf("%--c\n", c);
  printf("%05d\n", 42);     // 00042
  printf("%05dhola hoa\n", 7);
  printf("%05d ddHOa:\n", 12345);
  printf("%8cd\n", 123456);
  printf("%08d\n", 123456);
  printf("%60d\n", 4444);
||||||| parent of dfd1ebc (update)
  }
  char c = 'a';
  printf("%--c\n", c);
  printf("%05d\n", 42);     // 00042
  printf("%05dhola hoa\n", 7);
  printf("%05d ddHOa:\n", 12345);
  printf("%8cd\n", 123456);
  printf("%08d\n", 123456);
  printf("%60d\n", 4444);
	else
		write(1,format,1);
	}

  printf("|% d|\n", 42);   // "| 42|"
printf("|% d|\n", 0);    // "| 0|"
printf("|% d|\n", -42);  // "|-42|"
  printf("|%+ d|\n", 42);  // "|+42|"
*/
  printf("|% d|\n", 42);   // "| 42|"
printf("|% d|\n", 0);    // "| 0|"
printf("|% d|\n", -42);  // "|-42|"
  printf("|%+ d|\n", 42);  // "|+42|"


  return (0);
}
