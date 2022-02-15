/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:21:17 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/16 15:03:00 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str, t_stacks *stacks)
{
	int					i;
	int					sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_error(stacks);
	if (res > 2147483647 && sign == 1)
		ft_error(stacks);
	else if (res > 2147483648 && sign == -1)
		ft_error(stacks);
	return (res * sign);
}
