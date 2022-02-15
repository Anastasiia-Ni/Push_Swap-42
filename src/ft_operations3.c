/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:37 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 18:43:32 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_count_steps(int a, int b, int poz_b)
{
	if (a > 0 && b > 0 && poz_b != -1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0 && poz_b != -1)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}

void	ft_copy_rank(t_stacks *stacks)
{
	stacks->opt_av = stacks->tmp_av;
	stacks->opt_rb = stacks->tmp_rb;
	stacks->opt_ra = stacks->tmp_ra;
}

void	ft_from_sb_to_sa(t_stacks *stacks)
{
	t_stack	*tmp_sb;
	int		rank;
	int		min_rank;

	while (stacks->sb)
	{
		tmp_sb = stacks->sb;
		ft_index(stacks->sa);
		ft_index(stacks->sb);
		stacks->count_a = ft_size_stack(stacks->sa);
		stacks->count_b = ft_size_stack(stacks->sb);
		min_rank = ft_def_tmp_rank(stacks, tmp_sb);
		ft_copy_rank(stacks);
		while (tmp_sb)
		{
			rank = ft_def_tmp_rank(stacks, tmp_sb);
			if (rank < min_rank)
			{
				min_rank = rank;
				ft_copy_rank(stacks);
			}
			tmp_sb = tmp_sb->next;
		}
		ft_join_sb_to_sa(stacks);
	}
}

void	ft_min_to_top(t_stacks *stacks)
{
	int		op;
	t_stack	*tmp;
	t_stack	*min_node;

	tmp = stacks->sa;
	min_node = tmp;
	while (tmp)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		tmp = tmp->next;
	}
	stacks->count_a = ft_size_stack(stacks->sa);
	ft_index(stacks->sa);
	op = ft_find_part(stacks->count_a, min_node->i);
	if (op > 0)
		ft_distrib("ra", op, stacks);
	else
		ft_distrib("rra", op, stacks);
}

t_stack	*ft_del_back(t_stack **stack)
{
	t_stack	*back;
	t_stack	*tmp;

	back = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (back->next && back->next->next)
			back = back->next;
		tmp = back->next;
		back->next = NULL;
	}
	return (tmp);
}
