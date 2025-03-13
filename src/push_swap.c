/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/13 22:28:56 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pop(t_node **src, t_node **dest, int print)
{
	t_node	*temp;

	if (*src == NULL || !*src)
	{
		error_message(1);
		return ;
	}
	if (print)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

t_node	*push_three(t_node **a_stack, t_node **b_stack)
{
	t_node		*minimum;
	t_node		*maximum;
	int			i;

	i = lstsize(*a_stack);
	if (check_sort(a_stack) || (sort_rev(a_stack) && i <= 3))
		return (minimum = NULL);
	i = i - 3;
	minimum = check_min(*a_stack);
	maximum = check_max1(*a_stack);
	while (i--)
	{
		if (minimum->pos == (*a_stack)->pos)
			ft_rx(a_stack, 1);
		else if (maximum->pos == (*a_stack)->pos)
			ft_rx(a_stack, 1);
		if (minimum->pos != (*a_stack)->pos && maximum->pos != (*a_stack)->pos)
			push_pop(a_stack, b_stack, 1);
		else
			i++;
	}
	sort_three(a_stack);
	return (minimum);
}

void	q_sort(t_node **a_stack, t_node **b_stack)
{
	int			i;
	t_node		*minimum;
	t_node		*best;

	minimum = push_three(a_stack, b_stack);
	if (!minimum)
		return ;
	while ((*b_stack))
	{
		best = calc_cost_ab(*b_stack, *a_stack, minimum);
		go_to_best_cost(b_stack, a_stack, best);
		push_to_its_section(a_stack, b_stack, best);
	}
	i = find_node(a_stack, minimum->pos);
	while ((*a_stack)->pos != minimum->pos)
		take_movement(a_stack, i, 1);
}

void	turk(t_node **a_stack, t_node **b_stack)
{
	size_t	size_stack;
	int		is_sort;

	size_stack = lstsize(*a_stack);
	set_postion(*a_stack);
	is_sort = check_sort(a_stack);
	if (size_stack <= 2 && !is_sort)
		ft_rrx(a_stack, 1);
	else if (size_stack <= 3 && !is_sort)
	{
		if (!sort_rev(a_stack))
			sort_three(a_stack);
	}
	else if (size_stack == 5 && !is_sort)
		sort_five(a_stack, b_stack);
	else
	{
		q_sort(a_stack, b_stack);
	}
}

int	main(int argc, char *argv[])
{
	t_node		*node;
	t_node		*cur;
	int			flag;

	node = NULL;
	cur = NULL;
	flag = 0;
	if (argc == 1)
		return (1);
	h_in_pool(&node, &flag, argv);
	if (flag)
	{
		frees(&node);
		error_message(flag);
		exit(flag);
	}
	h_repeat_num(&node);
	turk(&node, &cur);
	frees(&node);
	frees(&cur);
}

/*
void print(t_node *list)
{
	while (list)
	{
		printf("%ld\n", list->x);
		list = list->next;
		sleep(0.3);
	}
}

void printpos(t_node *list)
{
	while (list)
	{
		printf("%i\n", list->cost);
		printf("---------->%ld\n", list->x);
		list = list->next;
		sleep(0.3);
	}
}
*/
