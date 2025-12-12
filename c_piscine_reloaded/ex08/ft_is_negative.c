/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:41:32 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/10 16:35:45 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar("N");
	}
	else
	{
		ft_putchar("P");
	}
}
//int	main(void)
//{
//	int	num;
//
//	num = 0;
//	ft_is_negative(num);
//	return (0);
//}
