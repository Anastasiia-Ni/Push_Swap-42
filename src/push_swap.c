/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:44:15 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 17:37:32 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_pred_sort(t_stacks *stacks)
{
	int	op;

	ft_index(stacks->sa);
	stacks->sort = ft_find_max_sorted(stacks->sa);
	stacks->count_a = ft_size_stack(stacks->sa);
	if (stacks->count_a - stacks->sort->i - stacks->sort->s > 0)
		op = stacks->sort->i + stacks->sort->s;
	else
		op = stacks->count_a - stacks->sort->i - stacks->sort->s;
	if (op < 0)
		op *= -1;
	op = ft_find_part(stacks->count_a, op);
	if (op > 0)
		ft_distrib("ra", op, stacks);
	else
		ft_distrib("rra", op, stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	if (!argv[1][0] || (argv[1][0] == ' ' && !argv[1][1]))
		return (0);
	if (!(ft_check_str(argv[1])))
		ft_only_error();
	stacks = ft_init_stacks(argc, argv);
	if (!stacks)
		ft_error(stacks);
	ft_pred_sort(stacks);
	if (stacks->count_a == 3)
		ft_three_sort(stacks);
	else if (stacks->count_a == 5)
		ft_five_sort(stacks);
	else
		ft_big_sort(stacks);
	ft_free (stacks);
	return (0);
}
