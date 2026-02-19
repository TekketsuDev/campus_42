/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:39:01 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/19 09:39:04 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_until(int fd, char *stash);
char	*extract_line(char *stash);
char	*save_remainder(char *stash);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		has_newline(char *s);

#endif
