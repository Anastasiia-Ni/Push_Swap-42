/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:40:16 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 18:43:42 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_swap(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
		return (1);
	}
	return (-1);
}

int	ft_push(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_add_head(to, ft_del_head(from));
		return (1);
	}
	return (-1);
}

int	ft_rotate(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_add_back(stack, ft_del_head(stack));
		return (1);
	}
	return (-1);
}

int	ft_rev_rotate(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_add_head(stack, ft_del_back(stack));
		return (1);
	}
	return (-1);
}
