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

#include "push_swap_bonus.h"

static	void	push(t_lst **dest, t_lst **src)
{
	t_lst	*tmp;

	if (!src || !*src)
		return ;
	tmp = (*src)->next;
	lst_addfront(dest, *src);
	*src = tmp;
	if (*src)
		(*src)->prev = NULL;
}

void	do_pa(t_lst **a_stack, t_lst **b_stack)
{
	if (b_stack && *b_stack)
		push(a_stack, b_stack);
}

void	do_pb(t_lst **a_stack, t_lst **b_stack)
{
	if (a_stack && *a_stack)
		push(b_stack, a_stack);
}
