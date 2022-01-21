/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:20:22 by jiyseo            #+#    #+#             */
/*   Updated: 2022/01/18 15:37:09 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char	*s, int	fd)
{
	if (!s || fd < 0)
		return ;
	write (fd, s, ft_strlen(s));
}
