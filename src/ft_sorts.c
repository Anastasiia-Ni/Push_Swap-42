/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:45 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 21:04:01 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_three_sort(t_stacks *stacks)
{
	if (stacks->sa->value > stacks->sa->next->value && \
		stacks->sa->value < stacks->sa->next->next->value)
		ft_distrib("sa", 1, stacks);
	else if (stacks->sa->value > stacks->sa->next->next->value)
		ft_distrib("ra", 1, stacks);
}

void	ft_five_sort(t_stacks *stacks)
{
	if (stacks->sort->s < 3)
	{
		ft_distrib("pb", 2, stacks);
		ft_three_sort(stacks);
	}
	else
		ft_from_sa_to_sb(stacks);
	ft_from_sb_to_sa(stacks);
	ft_min_to_top(stacks);
}

void	ft_big_sort(t_stacks *stacks)
{
	ft_from_sa_to_sb(stacks);
	ft_from_sb_to_sa(stacks);
	ft_min_to_top(stacks);
}

static void	ft_find_max_sort2(t_stack *stack, t_stack *tmp, t_stack *first)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_stack(stack);
	while (i < size)
	{
		if (tmp->next && tmp->next->value < tmp->value)
			break ;
		if (!tmp->next && first->value < tmp->value)
			break ;
		stack->s++;
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = first;
		i++;
	}
}

t_stack	*ft_find_max_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*max_sort;

	first = stack;
	max_sort = stack;
	while (stack)
	{
		tmp = stack;
		ft_find_max_sort2(stack, tmp, first);
		if (stack->s > max_sort->s)
			max_sort = stack;
		stack = stack->next;
	}
	return (max_sort);
}
