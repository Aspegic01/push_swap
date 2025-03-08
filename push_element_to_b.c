/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:12:46 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 21:13:21 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_in_range(t_lst **a, t_lst **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	while (*a)
	{
		if ((*a)->content <= range->sorted_array[range->start])
		{
			do_pb(a, b);
			do_rb(b);
			next_chunk(range);
		}
		else if ((*a)->content <= range->sorted_array[range->end])
		{
			do_pb(a, b);
			if (lst_size(*b) > 2 && (*b)->content < (*b)->next->content)
				do_sb(b);
			next_chunk(range);
		}
		else
			do_ra(a);
	}
}

void push_element_to_b(t_lst **a, t_lst **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	push_in_range(a, b, range);
}
