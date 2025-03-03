/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:38:04 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/03 15:38:47 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>

bool	stack_sort(t_stack *stack)
{
	if (!stack)
		return true;
	while(stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return false;
		stack = stack->next;
	}
	return true;
}

static void swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

    if (!*head || !(*head)->next)
        return;
    first = *head;
    second = (*head)->next;
    first->next = second->next;
    second->prev = first->prev;
    if (first->next)
        first->next->prev = first;
    second->next = first;
    first->prev = second;
    *head = second;
}

void	sa(t_stack **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	printf("sb");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	printf("sa\n");
	printf("sb\n");
}
