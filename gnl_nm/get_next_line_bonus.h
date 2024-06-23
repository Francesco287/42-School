/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:37:09 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/23 17:15:29 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*rftls(int fd, char *strl);
char	*get_line(char *strl);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *strl, char *buff);
char	*renew_left_str(char *strl);

#endif
