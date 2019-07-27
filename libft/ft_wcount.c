/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:56:13 by apappas           #+#    #+#             */
/*   Updated: 2019/06/19 08:07:38 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcount(const char *str, char delim)
{
	int count;

	count = 0;
	while (*str == delim)
		str++;
	while (*str)
	{
		while (*str != delim && *str)
			str++;
		while (*str == delim)
			str++;
		count++;
	}
	return (count);
}
