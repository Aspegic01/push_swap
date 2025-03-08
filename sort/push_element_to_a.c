/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:11:47 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 21:12:28 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_value(t_lst *stack)
{
	int	max_value;

	max_value = stack->content;
	while (stack)
	{
		if (stack->content > max_value)
			max_value = stack->content;
		stack = stack->next;
	}
	return (max_value);
}

int	get_position(t_lst *stack, int max_value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->content == max_value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
}

void	push_elements_to_a(t_lst **a, t_lst **b)
{
	int	max_value;
	int	pos;
	int	size;

	if (!a || !b)
		return ;
	while (*b)
	{
		max_value = find_max_value(*b);
		pos = get_position(*b, max_value);
		size = lst_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->content != max_value)
				do_rb(b);
		}
		else
		{
			while ((*b)->content != max_value)
				do_rrb(b);
		}
		do_pa(a, b);
		if (*b && (*b)->content > (*a)->content)
			do_ra(a);
	}
}
