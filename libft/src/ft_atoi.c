/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:32:47 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:32:52 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int main(void)
{
  const char *nptr = "aa443222aa";
  const char *naptr = "\0443222aa";
  const char *naaptr = "22aa";
  //assert(strtol(nptr, NULL, 10));
  printf("NPTR (ft_ATOI):%d \n", ft_atoi(nptr));
  printf("NAAPTR (ATOI):%d\n", atoi(naaptr));
 int a = atoi(naptr);
printf("a_ATOI_NAPTR:%d\n", a);
a = atoi(nptr);
printf("a2_ATOI_NPTR:%d\n", a);

  return (0);
}
*/
