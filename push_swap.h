/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:32:21 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/02 15:38:10 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <limits.h>

typedef struct s_stack
{
	int	nbr;
	int	index;
	struct s_stack *taget_node;
	struct s_stack *next;
	struct s_stack *prev;

} t_stack;

void	ft_error(void);
void	creat_stack(t_stack **a, char **av);
int check_args(char **av);
bool stack_sort(t_stack *stack);
void	sa(t_stack **a);
bool	ft_syntax_check(char *argv);
int	ft_checksorted(t_stack *stack_a);
#endif
