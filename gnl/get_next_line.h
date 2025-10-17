/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:36:11 by rxue              #+#    #+#             */
/*   Updated: 2024/12/10 18:37:48 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		found_newline(char *str);
int		ft_strlen1(char *s);
void	*ft_memcpy1(void *dest, const void *src, int n);
char	*ft_strjoin1(char *s1, char *s2);
void	*ft_calloc1(size_t nmemb, size_t size);

#endif
