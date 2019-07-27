/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:07:15 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:03:58 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	ptr = (void *)(malloc)(size);
	if (ptr)
		ft_memset(ptr, 0, size);
	return (ptr);
}
