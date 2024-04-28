/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:02:05 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/05 10:33:24 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_to_line(char *line, int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_len_to_char(const char *str, char c);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t dstsize);
char	*ft_str_join(char const *s1, char const *s2);

#endif
