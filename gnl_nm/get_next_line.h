/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:29:04 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/23 17:16:20 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*rftls(int fd, char *strl);
char	*get_line(char *strl);
char	*ft_strjoin(char *strl, char *buff);
size_t	ft_strlen(char *s);
char	*renew_left_str(char *strl);

#endif
