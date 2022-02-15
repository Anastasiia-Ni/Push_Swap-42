/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:47:23 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/16 12:47:26 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_size(const char *str, char set)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == set))
			str++;
		if (*str && (*str != set))
		{
			count++;
			while (*str && (*str != set))
				str++;
		}
	}
	return (count);
}

static char	*ft_word(const char *str, char set)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	word = (char *)ftp_calloc((i + 1), sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (str[i] && (str[i] != set))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill(char const *s, char c, char	**array, int i)
{
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			array[i] = ft_word(s, c);
			if (!array[i])
			{
				while (i)
					free (array[i--]);
				free (array);
				return (0);
			}
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (i);
}

char	**ft_split_nbr(char *s, char c)
{
	int		i;
	char	**array;

	i = 0;
	if (!s)
	{
		array = (char **)ftp_calloc(1, sizeof(char));
		if (!array)
			 return (0);
		return (&array[0]);
	}
	array = (char **)ftp_calloc((ft_size(s, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = ft_fill(s, c, array, i);
	array[i] = ((void *)0);
	return (array);
}
