/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 04:23:39 by nqasem           #+#    #+#             */
/*   Updated: 2024/10/07 18:04:51 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*ft_strjoin_line(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr_vline(char *str);

#endif
