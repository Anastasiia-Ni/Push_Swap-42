/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:41:02 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/16 12:33:46 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_stack_free(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	ft_free(t_stacks *stacks)
{
	if (stacks && stacks->sa)
		ft_stack_free(stacks->sa);
	if (stacks && stacks->sb)
		ft_stack_free(stacks->sb);
	if (stacks)
		free(stacks);
}

void	ft_error(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_free(stacks);
	exit(1);
}

void	ft_only_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
