/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:20:59 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 23:11:04 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
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

int	main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack;

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
		if (is_sorted(&a_stack) != 1)
		{
			if (lst_size(a_stack) == 2)
				do_sa(&a_stack);
			if (lst_size(a_stack) == 3)
				sort_three(&a_stack);
			else
				large_sort(&a_stack, &b_stack, lst_size(a_stack));
		}
	}
	stackclear(&a_stack);
	stackclear(&b_stack);
}
