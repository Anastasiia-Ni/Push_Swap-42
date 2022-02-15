/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:48:07 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/16 12:48:08 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

static int	ft_distrib_op2(char *op, t_stacks *stacks)
{
	int	len;
	int	res;

	len = ft_strlen(op);
	res = 0;
	if (len == 3 && op[0] == 'r' && op[1] == 'r' && \
	(op[2] == 'r' || op[2] == 'a'))
		res = ft_rev_rotate(&stacks->sa);
	if (len == 3 && op[0] == 'r' && op[1] == 'r' && \
	(op[2] == 'r' || op[2] == 'b'))
		res = ft_rev_rotate(&stacks->sb);
	return (res);
}

static int	ft_distrib_op(char *op, t_stacks *stacks)
{
	int	len;
	int	res;

	len = ft_strlen(op);
	res = 0;
	if (len == 2 && op[0] == 's' && (op[1] == 's' || op[1] == 'a'))
		res = ft_swap(&stacks->sa);
	if (len == 2 && op[0] == 's' && (op[1] == 's' || op[1] == 'b'))
		res = ft_swap(&stacks->sb);
	if (len == 2 && op[0] == 'p' && op[1] == 'a')
		res = ft_push(&stacks->sb, &stacks->sa);
	if (len == 2 && op[0] == 'p' && op[1] == 'b')
		res = ft_push(&stacks->sa, &stacks->sb);
	if (len == 2 && op[0] == 'r' && (op[1] == 'r' || op[1] == 'a'))
		res = ft_rotate(&stacks->sa);
	if (len == 2 && op[0] == 'r' && (op[1] == 'r' || op[1] == 'b'))
		res = ft_rotate(&stacks->sb);
	ft_distrib_op2(op, stacks);
	if (res < 0)
		ft_error(stacks);
	return (res);
}

void	ft_distrib(char *op, int t, t_stacks *stacks)
{
	t = ft_abs(t);
	while (t)
	{
		ft_distrib_op(op, stacks);
		write(1, op, ft_strlen(op));
		write(1, "\n", 1);
		t--;
	}
}
