/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 02:34:25 by jiyseo            #+#    #+#             */
/*   Updated: 2022/01/19 20:41:04 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	**ft_free(char	**res)
{
	unsigned int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

long long	ft_word_cnt(char const *str, char c)
{
	long long	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			++cnt;
			while (*str && *str != c)
				++str;
			continue ;
		}
		++str;
	}
	return (cnt);
}

void	ft_strcpy(char *dst, char *from, char const *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = 0;
}

char	**ft_split_alloc(char const	*str, char	c)
{
	if (!str)
		return (NULL);
	return ((char **)malloc(sizeof(char *) * (ft_word_cnt(str, c) + 1)));
}

char	**ft_split(char const *str, char c)
{
	     char	**res;
	long long	i;
	     char	*from;

	res = ft_split_alloc(str, c);
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			from = (char *)str;
			while (*str && *str != c)
				++str;
			res[i] = (char *)malloc(sizeof(char) * (str - from + 1));
			if (!(res[i]))
				return (ft_free(res));
			ft_strcpy(res[i++], from, str);
			continue ;
		}
		++str;
	}
	res[i] = 0;
	return (res);
}
