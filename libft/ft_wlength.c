/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:56:32 by apappas           #+#    #+#             */
/*   Updated: 2019/06/13 15:03:26 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wlength(const char *str, char delim)
{
	int i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != delim && str[i] != '\0')
		i++;
	return (i);
}