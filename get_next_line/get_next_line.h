/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:36:55 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/22 16:36:55 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int  fd);
size_t			ft_strlen(char *s);
char			*ft_strdup(char *s);
int				ft_strchr(char *s, char c);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strjoin(char *s1, char *s2);

#endif