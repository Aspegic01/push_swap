/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:20:59 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/02 17:40:20 by mlabrirh         ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	if (initstack(ac, av, &a_stack) == 0)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	else if (check_dup(a_stack) == - 1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	else
	{
		ft_index(&a_stack);
		if (is_sorted(&a_stack) != 1)
		{
			radix_sort(&a_stack, &b_stack);
		}
	}
	//print_stack(a_stack);
	stackclear(&a_stack);
	stackclear(&b_stack);
}
