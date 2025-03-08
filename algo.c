/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:19:14 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 21:15:15 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_offset(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 12);
	else
		return (size / (size / 2));
}

void	init_range(t_lst **a, t_range *range, int size)
{
	int	*array;

	array = stack_to_array(*a, size);
	if (!array)
		return ;
	sorted_array(array, size);
	range->offset = find_offset(size);
	range->sorted_array = array;
	range->size = size;
	range->start = 0;
	range->end = range->offset;
}

void	next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start += 1;
	if (range->end < range->size - 1)
		range->end += 1;
}

void	large_sort(t_lst **a, t_lst **b, int size)
{
	t_range	*range;

	range = (t_range *)malloc(sizeof(t_range));
	if (!range)
		return ;
	init_range(a, range, size);
	push_element_to_b(a, b, range);
	push_elements_to_a(a, b);
	free(range->sorted_array);
	free(range);
}
