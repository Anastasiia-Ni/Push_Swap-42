/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:56 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/15 18:50:12 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_from_sa_to_sb(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->sa;
	while (tmp && tmp->i != stacks->sort->i)
	{
		tmp = tmp->next;
		ft_distrib("pb", 1, stacks);
	}
}

void	ft_join_sb_to_sa(t_stacks *stacks)
{
	stacks->tmp_ra = ft_abs(stacks->opt_ra);
	stacks->tmp_rb = ft_abs(stacks->opt_rb);
	while (((stacks->opt_rb > 0 && stacks->opt_ra > 0) || (stacks->opt_rb < 0 \
	&& stacks->opt_ra < 0)) && stacks->tmp_rb && stacks->tmp_ra \
	&& stacks->opt_av != -1)
	{
		if (stacks->opt_rb > 0)
			ft_distrib("rr", 1, stacks);
		else
			ft_distrib("rrr", 1, stacks);
		stacks->tmp_rb--;
		stacks->tmp_ra--;
	}
	if (stacks->opt_rb > 0)
		ft_distrib("rb", stacks->tmp_rb, stacks);
	else
		ft_distrib("rrb", stacks->tmp_rb, stacks);
	if (stacks->opt_av != -1)
	{
		if (stacks->opt_ra > 0)
			ft_distrib("ra", stacks->tmp_ra, stacks);
		else
			ft_distrib("rra", stacks->tmp_ra, stacks);
	}
	ft_distrib("pa", 1, stacks);
}

int	ft_find_i_for_join(t_stack *stack, int sb_value)
{
	int		less;
	t_stack	*find_i;

	less = 0;
	find_i = NULL;
	while (stack)
	{
		if ((less == 0) || (less < 0 && stack->value - sb_value < 0 && \
		stack->value - sb_value > less) || (less > 0 && stack->value - \
		sb_value < less))
		{
			less = stack->value - sb_value;
			find_i = stack;
		}
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	if (find_i == stack && less < 0)
		return (-1);
	if (less < 0)
		return (find_i->i + 1);
	else
		return (find_i->i);
}

int	ft_def_tmp_rank(t_stacks *stacks, t_stack *tmp_sb)
{
	stacks->tmp_av = ft_find_i_for_join(stacks->sa, tmp_sb->value);
	stacks->tmp_ra = ft_find_part(stacks->count_a, stacks->tmp_av);
	stacks->tmp_rb = ft_find_part(stacks->count_b, tmp_sb->i);
	return (ft_count_steps(stacks->tmp_ra, stacks->tmp_rb, stacks->tmp_av));
}
