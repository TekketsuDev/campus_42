/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:28:49 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/12 15:41:26 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	length;

	length = 0;
	while (s1[length] != '\0' && s2[length] != '\0')
	{
		if (s1[length] != s2[length])
			return (s1[length] - s2[length]);
		length++;
	}
	return (s1[length] - s2[length]);
}
/*
int main(void)
{
char *string1 = "Crusty Dusty\0";
char *string2 = "Crusty Dusty";


	printf("%d\n",ft_strcmp(string1,string2));
	return 0;
}
*/
