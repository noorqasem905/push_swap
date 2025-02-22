/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:00:02 by yhamdan           #+#    #+#             */
/*   Updated: 2024/10/07 17:54:24 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_line(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*st;

	j = 0;
	i = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 && !s2)
		return (NULL);
	st = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		st[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		st[i + j] = s2[j];
		j++;
	}
	st[i + j] = '\0';
	return (free(s1), free(s2), st);
}

char	*ft_strchr_vline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
