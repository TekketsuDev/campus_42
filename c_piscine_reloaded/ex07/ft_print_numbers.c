/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:50:22 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/10 13:09:16 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	n;

	n = 48;
	while (n <= 57)
	{
		ft_putchar(n);
		n++;
	}
}

//int	main(void)
//{
//	ft_print_number();
//	return (0);
//}
