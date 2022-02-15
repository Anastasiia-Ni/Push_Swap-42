/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:34:20 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 18:34:53 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_find_last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->i = i;
		i++;
		stack = stack->next;
	}
}

int	ft_find_part(int len, int poz)
{
	if (len / 2 >= poz)
		return (poz);
	else
		return (poz - len);
}

int	ft_size_stack(t_stack *list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
