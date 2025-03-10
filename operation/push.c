/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:33:42 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 14:35:51 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_lst **a_stack, t_lst **b_stack)
{
	t_lst	*tmp;

	if (!b_stack)
		return ;
	tmp = (*b_stack)->next;
	lst_addfront(a_stack, *b_stack);
	*b_stack = tmp;
	if (*b_stack)
		(*b_stack)->prev = NULL;
}

void	do_pa(t_lst **a_stack, t_lst **b_stack)
{
	push(a_stack, b_stack);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_lst **a_stack, t_lst **b_stack)
{
	push(b_stack, a_stack);
	ft_putstr_fd("pb\n", 1);
}
