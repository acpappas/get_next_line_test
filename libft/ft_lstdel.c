/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:33:43 by apappas           #+#    #+#             */
/*   Updated: 2019/06/24 14:00:04 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = *alst;
	while (*alst)
	{
		*alst = (*alst)->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = *alst;
	}
	*alst = NULL;
}
