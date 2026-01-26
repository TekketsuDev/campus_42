/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:17:54 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/26 18:49:46 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t  slen;
  char*   subs;
  size_t     i;

  i = 0;
  if(!s)
    return (NULL);
  if(ft_strlen(s) < start)
    return (ft_strdup(""));
  slen = ft_strlen(s + start);
  if (slen < len)
    len = slen;
  subs = malloc(sizeof(*subs) * (slen + 1));
  if (!subs)
    return (NULL);
  while (i < len)
  {
    subs[i] = s[start + i];
    i++;
  }
  subs[i] = '\0';
  return (subs);
}
