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

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	i;

	factorial = 1;
	i = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (i <= nb)
	{
		factorial *= i;
		i++;
	}
	return (factorial);
}
