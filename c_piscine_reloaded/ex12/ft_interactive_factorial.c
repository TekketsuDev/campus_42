/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_factorial.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:08:01 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/10 16:23:03 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_interactive_factorial(int nb)
{
	int	factorial;
	int	i;

	factorial = 1;
	i = 0;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 1 || nb == 0)
	{
		return (1);
	}
	while (i <= nb)
	{
		factorial *= i;
		i++;
	}
	return (factorial);
}

//int	main(void)
//{
//	int	num;
//
//	num = 0;
//	ft_is_negative(num);
//	return (0);
//}
