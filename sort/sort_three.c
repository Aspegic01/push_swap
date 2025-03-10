/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:43:02 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/10 14:44:05 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_lst **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && first < third)
		do_sa(a);
	else if (first > second && second > third)
	{
	do_sa(a);
	do_rra(a);
	}
	else if (first > second && second < third && first > third)
		do_ra(a);
	else if (first < second && second > third && first < third)
	{
	do_sa(a);
	do_ra(a);
	}
	else if (first < second && second > third && first > third)
		do_rra(a);
}
