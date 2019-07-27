/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:34:26 by apappas           #+#    #+#             */
/*   Updated: 2019/06/24 13:59:48 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	fresh = f(lst);
	if (!fresh)
		return (NULL);
	head = fresh;
	lst = lst->next;
	while (lst)
	{
		fresh->next = f(lst);
		lst = lst->next;
		fresh = fresh->next;
	}
	return (head);
}
