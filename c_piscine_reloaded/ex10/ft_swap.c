/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:18:47 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/16 13:44:02 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//int	main(void)
//{	
//	int	num;
//	int	numa;
//	num = 40;
//	numa= 42;
//	
//	printf("%d",num);
//	printf("\n");
//	printf("%d \n",numa);
//	ft_swap(&num, &numa);
//	
//	printf("After \n");
//	printf("%d",num);
//	printf("\n");
//	printf("%d",numa);
//	return (0);
//}
