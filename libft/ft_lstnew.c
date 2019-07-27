/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:45:03 by apappas           #+#    #+#             */
/*   Updated: 2019/06/17 11:47:38 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		head->content = ft_memalloc(content_size);
		head->content = ft_memcpy(head->content, content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
