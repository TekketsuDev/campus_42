/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:18:47 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/16 13:43:06 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{	
	int	num;
	int	numa;
	int	ptrd;
	int	ptrm;
	num = 40;
	numa= 42;
	ptrd = 0;
	ptrd = 0;	
	printf("%d",ptrd);
	printf("\n");
	printf("%d \n",ptrd);
	
	printf("%d",num);
	printf("\n");
	printf("%d \n",numa);
	ft_div_mod(num, numa,&ptrd, &ptrm);
	
	printf("After \n");
	printf("%d",ptrd);
	printf("\n");
	printf("%d",ptrm);
	
	return (0);
}
*/
