/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:30:15 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/16 17:07:51 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elem;
	void	*value;

	new = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		value = f(lst->content);
		elem = ft_lstnew(value);
		if (!elem)
		{
			del(value);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, elem);
		lst = lst->next;
	}
	return (new);
}
