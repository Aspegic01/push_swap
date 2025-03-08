/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:20:59 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 20:06:24 by Aspegic01        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>


static t_lst	*get_min(t_lst **stack)
{
	t_lst	*lst;
	t_lst	*lst_min;
	int		min;

	if (!(*stack))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *stack;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || lst->content < lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	ft_index(t_lst **stack)
{
	t_lst	*lst;
	int		index;

	index = 0;
	lst = get_min(stack);
	while (lst)
	{
		lst->index = index++;
		lst = get_min(stack);
	}
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	check_dup(t_lst *stack)
{
	int		tmp;
	t_lst	*dup;

	while (stack && stack->next)
	{
		tmp = stack->content;
		dup = stack;
		while (dup->next)
		{
			dup = dup->next;
			if (dup->content == tmp)
				return (-1);
		}
		stack = stack->next;
	}
	return (1);
}

static void	stackclear(t_lst **stack)
{
	if (!stack || !(*stack))
		return ;
	stackclear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

static int	initstack(int ac, char **av, t_lst **a_stack)
{
	int			i;
	int			j;
	char		**split;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX
				|| ft_atol(split[j]) < INT_MIN)
				return (0);
			lst_addback(a_stack, lst_new(ft_atoi(split[j])));
			j++;
		}
		ft_free(split);
		i++;
	}
	return (1);
}

void	print_stack(t_lst *stack)
{
	while (stack)
	{
		printf("|    [%d]    |\n", stack->content);
		stack = stack->next;
	}
}

int find_offset(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 12);
	else
		return (size / (size / 2));
}

void sorted_array(int *array, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int *stack_to_array(t_lst *stack, int size)
{
	int *array;
	int i;

	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	return (array);
}

void push_element_to_b(t_lst **a, t_lst **b, t_range *range)
{
	int i;

	for (i = 0; i < range->size; i++)
	{
		if ((*a)->content >= range->sorted_array[range->start] &&
			(*a)->content <= range->sorted_array[range->end])
		{
			do_pb(a, b);
		}
		else
			do_ra(a);
	}
}

void push_elements_to_a(t_lst **a, t_lst **b)
{
	while (*b)
	{
		do_pa(a, b);
	}
}

void init_range(t_lst **a, t_range *range, int size)
{
	int *array;

	array = stack_to_array(*a, size);
	if (!array)
		return;
	sorted_array(array, size);
	range->offset = find_offset(size);
	range->sorted_array = array;
	range->size = size;
	range->start = 0;
	range->end = range->offset;
}

void next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start += 1;
	if (range->end < range->size - 1)
		range->end += 1;
}

void large_sort(t_lst **a, t_lst **b, int size)
{
	t_range *range;

	range = (t_range *)malloc(sizeof(t_range));
	if (!range)
		return;
	init_range(a, range, size);
	push_element_to_b(a, b, range);
	push_elements_to_a(a, b);
	free(range->sorted_array);
	free(range);
}

int main(int ac, char **av)
{
	t_lst *a_stack;
	t_lst *b_stack;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	if (initstack(ac, av, &a_stack) == 0)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	else if (check_dup(a_stack) == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	else
	{
		ft_index(&a_stack);
		int size = lst_size(a_stack);
		if (is_sorted(&a_stack) != 1)
		{
			large_sort(&a_stack, &b_stack, size);
		}
	}
	print_stack(a_stack);
	stackclear(&a_stack);
	stackclear(&b_stack);
}
