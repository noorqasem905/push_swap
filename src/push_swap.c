/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/01/01 22:08:00 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	h_ft_atoi(const char *str, int *flag, size_t *sum)
{
	int		i;
	int		neg;
	long	c;

	c = 0;
	i = 0;
	neg = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) && !(*flag))
	{
		c = (c * 10) + (str[i] - '0');
		i++;
	}
	if ((str[i] && !ft_isdigit(str[i])) || (*sum)++ > 10)
		*flag = 1;
	return (c * neg);
}

void	insertend(t_node **root, long new_value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		exit(99);
		return ;
	}
	new_node->x = new_value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		(*root) = new_node;
		return ;
	}
	curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	ft_rx(t_node **list, int which)
{
	t_node	*prev;
	t_node	*cur;

	if ((*list) == NULL)
		return ;
	if ((*list)->next == NULL)
		return ;
	prev = *list;
	cur = prev->next;
	while (cur->next)
	{
		prev = prev->next;
		if (prev->next)
			cur = prev->next;
	}
	cur->next = (*list);
	prev->next = NULL;
	(*list) = cur;
	if (which == 1)
		write(1, "ra\n", 3);
	else if (which == 0)
		write(1, "rb\n", 3);
}

void	ft_rrx(t_node **b_list, int which)
{
	t_node	*curr;

	if ((*b_list) == NULL)
		return ;
	if ((*b_list)->next == NULL)
		return ;
	curr = *b_list;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = (*b_list);
	curr = (*b_list)->next;
	(*b_list)->next = NULL;
	*b_list = curr;
	if (which == 1)
		write(1, "rra\n", 4);
	else if (which == 0)
		write(1, "rrb\n", 4);
}

void	ft_sx(t_node **list, int which)
{
	t_node	*curr;

	if ((*list) == NULL)
		return ;
	if ((*list)->next == NULL)
		return ;
	curr = (*list)->next;
	(*list)->next = (*list)->next->next;
	curr->next = (*list);
	*list = curr;
	if (which == 1)
		write(1, "sa\n", 3);
	else if (which == 0)
		write(1, "sb\n", 3);
}

void	ft_rr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	ft_rx(b_list, 5);
	ft_rx(b_list, 5);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	ft_rrx(a_list, 5);
	ft_rrx(b_list, 5);
	write(1, "rrr\n", 4);
}

void	frees(t_node **root)
{
	t_node	*cur;
	t_node	*cur2;

	cur = *root;
	while (cur != NULL)
	{
		cur2 = cur;
		cur = cur->next;
		free(cur2);
	}
	free(cur);
	*root = NULL;
}

void	push_pop(t_node **push, t_node **take, int which_stack)
{
	t_node	*cur;

	if (*push == NULL)
	{
		write(1, "The stack is empty\n", 20);
		return ;
	}
	if (which_stack)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	if ((*take) == NULL)
	{
		cur = *push;
		*push = (*push)->next;
		cur->next = NULL;
		*take = cur;
		return ;
	}
	cur = *push;
	*push = (*push)->next;
	cur->next = *take;
	*take = cur;
}

t_node	*max_num(t_node **list)
{
	t_node	*find;
	t_node	*max;

	find = *list;
	max = find;
	find = find->next;
	while (find)
	{
		if (find->x > max->x)
			max = find;
		find = find->next;
	}
	return (max);
}

t_node	*last(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_node *lst)
{
	int		counter;
	t_node	*temp;

	while (!lst)
		return (0);
	counter = 1;
	temp = (t_node *)lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

void print(t_node *list)
{
	while (list)
	{
		printf("%ld\n", list->x);
		list = list->next;
		sleep(0.3);
	}
}

void	b_test(t_node **a_stack, t_node **b_stack)
{
	ft_rx(a_stack,1);
	ft_rx(a_stack,1);
	// print(*a_stack);
	push_pop(a_stack, b_stack, 1);
	push_pop(a_stack, b_stack, 1);
	ft_rrx(a_stack,1);
	ft_rrx(a_stack,1);
	print(*a_stack);
}
int	len_num_t(long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	turk(t_node **a_stack, t_node **b_stack)
{
	t_node	*cur;
	size_t	i;
	int	index;
	int  div;
	int empty;
	int div_index = 1;

	empty = 0;
	div = len_num_t((max_num(a_stack)->x));
 	while (0 < div--)
	{	
		index = 0;
		if(!empty)
		{
			cur = last(*a_stack);
			// printf("-------------------------------stack one \n");
			// print(*a_stack);
			while (index < 10)
			{
				empty = 1;
				i = lstsize(*a_stack);
				while (0 < i--)
				{
					if (((cur->x)/div_index)%10 == index)
					{
						ft_rx(a_stack, 1);
						push_pop(a_stack, b_stack, 1);
						if (cur != NULL)
    	    	            cur = last(*a_stack);
					}
					else
					{
						ft_rx(a_stack, 1);
 						cur = last(*a_stack);
						if (cur == NULL)
    	    	            return;
					}
				}
				index++;
			}
		}
 		else
		{
			cur = last(*b_stack);
			// printf("-------------------------------stack two \n");
			// print(*b_stack);
			while (index < 10)
			{
				empty = 0;
				i = lstsize(*b_stack);
				while (0 < i--)
				{
					if (((cur->x)/div_index)%10 == index)
					{
						ft_rx(b_stack, 0);
						push_pop(b_stack, a_stack, 0);
						if (cur != NULL)
    	    	            cur = last(*b_stack);
					}
					else
					{
						ft_rx(b_stack, 0);
 						cur = last(*b_stack);
						      if (cur == NULL)
    	    	            return;
					}
				}
				index++;
			}
			
		}
	
		div_index = div_index * 10;
		// printf("%i\n", div_index);
	}
	i = lstsize(*a_stack);
	int j;
	if (((*a_stack)))
	{

			if ((*a_stack)->x != div)
			{
				j = lstsize(*a_stack);
				while (j--)
				{
					ft_rx(a_stack, 1);
 					push_pop(a_stack, b_stack, 1);
				}
				i = lstsize(*b_stack);
				while (i--)
				{
					push_pop(b_stack, a_stack, 0);
				}
			}
	}
	else
	{
		i = lstsize(*b_stack);
		while (i--)
		{
				push_pop(b_stack, a_stack, 0);
		}
	}

}	

/* void	turk(t_node **a_stack, t_node **b_stack)
{
	// t_node	*cur;
  	int	i;
	int index;
	int	size;
 
	// cur = (*a_stack);
	size = lstsize(*a_stack);
 	i = 0;
	if (index){}
	while (i < 10)
	{	
 		index = size;
			printf("-------------->%i\n", index);

 		while (--index > 0)
		{	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
			if (((((*a_stack) ->x) * 1) % 10) == i)
			{
				push_pop(a_stack, b_stack, 1);
 


			}

 			ft_rx(a_stack, 1);
	

				
							printf("-------------------THE VALUE-->%li\n", (*a_stack)->x);
							printf("-------------------index-->%i\n", i);

		
		}print(*a_stack);
			// printf("-------------------THE VALUE-->%li\n", (*a_stack)->x);

		i++;
	}
	
	if (a_stack || b_stack){}
	// t_node	*end;
	// t_node	*tmp;
	// push_pop(a_stack, b_stack, 1);
	// push_pop(a_stack, b_stack, 1);
	// push_pop(a_stack, b_stack,		1);
	// push_pop(a_stack, b_stack, 1);
	// st2 = *b_stack;
	// while (1)
	// {
	// }
	// first = *b_stack;
	// if ((first)->x < (first)->next->x)
	// 	ft_rx(b_stack, 0);
} */

int	main(int argc, char *argv[])
{
	t_node	*node;
	t_node	*cur;
 	int		flag;

	node = NULL;
	cur = NULL;
 	node = NULL;
	flag = 0;
	if (argc == 1)
		return (1);
	h_in_pool(&node, &flag, argv);
	if (flag)
	{
		frees(&node);
		exit(5);
	}
	h_repeat_num(&node);
	turk(&node, &cur);
	print(node);
	// print(cur);
	frees(&node);
	frees(&cur);
}

/*
int	main4(void)
{
	int	temp;
	int	i;
		int p;

			temp = 0;g
		i = 0;
		int z ;
		int arr[]={3,4,1,8,0,6,2};
			z  = 6;
		p = arr[i];
		i++;
		while (i <= z)
		{
				while (arr[i] <= p)
						i++;
				while(p < arr[z])
						z--;
				if ((arr[i] > p) && (arr[z] <= 3))
				{
						printf("PJJd");
						temp = arr[z];
						arr[z] = arr[i];
						arr[i] = temp;
																int n=0;
				printf("THE VALUE: { ");
				while(arr[n])
				{
						printf("%i ,", arr[n]);
						n++;
				}
				printf("%i ,", arr[n]);
				n++;
				printf("%i ,", arr[n]);
				n++;
				printf("%i ,", arr[n]);
				n++;
				printf("%i ,", arr[n]);
				n++;
				printf(" }");
				}
				if (i > z)
						break ;
			}
				{
										int n=0;
printf("THE VALUE: { ");
				while(arr[n])
				{
						printf("%i ,", arr[n]);
						n++;
				}
						printf("%i ,", arr[n]);
						n++;
							printf("%i ,", arr[n]);
						n++;
								printf("%i ,", arr[n]);
						n++;
				printf(" }");
		}
}
 */