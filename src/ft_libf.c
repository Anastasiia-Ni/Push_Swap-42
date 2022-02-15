/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:48:51 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/01 12:00:21 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void	*ftp_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	sym;

	ptr = (unsigned char *)b;
	sym = (unsigned char)c;
	while (len--)
		*ptr++ = sym;
	return (b);
}

static void	ftp_bzero(void *s, size_t n)
{
	ftp_memset(s, 0, n);
}

void	*ftp_calloc(size_t count, size_t size)
{
	void	*str;

	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ftp_bzero(str, count * size);
	return (str);
}
