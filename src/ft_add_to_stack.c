/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:44:17 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 18:44:19 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->i = 0;
	new->s = 1;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*back;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	back = ft_find_last_node(*stack);
	back->next = new;
}

t_stack	*ft_to_list(t_stack **stack, int value)
{
	t_stack	*new;

	new = ft_new_node(value);
	if (!new)
		return (NULL);
	ft_add_back(stack, new);
	return (*stack);
}

void	ft_add_head(t_stack **stack, t_stack *head)
{
	if (!(*stack))
		*stack = head;
	else
	{
		head->next = *stack;
		*stack = head;
	}
}

t_stack	*ft_del_head(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}
