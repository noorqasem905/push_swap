/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2024/12/23 17:51:15 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct node
{
	long		x;
	struct node	*next;
}				t_node;

long	h_ft_atoi(const char *str, int *flag, size_t *sum);
void	insertend(t_node **root, long new_value);
void	frees(t_node **root);
void	h_in_pool(t_node **node, int *flag, char **argv);
void	h_repeat_num(t_node **node);
#endif
