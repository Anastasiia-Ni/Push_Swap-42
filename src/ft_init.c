/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:35:51 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 17:36:26 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	ft_init_stack_a(int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	nbr;

	i = (argc != 2);
	if (argc == 2)
		argv = ft_split_nbr(argv[1], ' ');
	while ((int)argv[i])
	{
		if (!(ft_check_str(argv[i])))
			ft_error(stacks);
		nbr = ft_atoi(argv[i], stacks);
		if (!ft_not_dup(stacks->sa, nbr) || !(ft_to_list(&stacks->sa, nbr)))
			ft_error(stacks);
		i++;
	}
	stacks->count_a = ft_size_stack(stacks->sa);
}

t_stacks	*ft_init_stacks(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error(stacks);
	stacks->sa = NULL;
	stacks->sb = NULL;
	ft_init_stack_a(argc, argv, stacks);
	return (stacks);
}
