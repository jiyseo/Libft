/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:02:20 by jiyseo            #+#    #+#             */
/*   Updated: 2022/01/18 15:44:21 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list	**lst, void	(*del)(void *))
{
	t_list	*next;
	t_list	*now;

	now = *lst;
	if (!lst || !del)
		return ;
	while (now)
	{
		next = now->next;
		ft_lstdelone(now, del);
		now = next;
	}
	*lst = NULL;
}
