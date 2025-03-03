/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:06:43 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/02 18:13:42 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void add_node(t_stack **stack, int nbr)
{
    t_stack *new_node;
    t_stack *temp;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        ft_error();
    new_node->nbr = nbr;
    new_node->next = NULL;
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

void	creat_stack(t_stack **a, char **av)
{
	int	i;
	long n;

	i = 0;
	while(av[i])
	{
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error();
		add_node(a, (int)n);
		i++;
	}
}
