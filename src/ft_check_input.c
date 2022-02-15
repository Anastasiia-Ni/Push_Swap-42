/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:04:45 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/16 13:15:30 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_ischarspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_not_dup(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_str(char *str)
{
	int	i;
	int	sign;
	int	is_nbr;

	i = 0;
	sign = 0;
	is_nbr = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			is_nbr++;
		else if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			sign++;
		else if ((ft_ischarspace(str[i])))
		{
			if ((sign != 0 && is_nbr == 0) || ft_ischarspace(str[i - 1]))
				ft_only_error();
			sign = 0;
			is_nbr = 0;
		}
		else
			ft_only_error();
		i++;
	}
	return (1);
}
