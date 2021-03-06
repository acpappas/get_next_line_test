/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:25:52 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:33:03 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int a;

	a = 0;
	if (c >= 'a' && c <= 'z')
	{
		a = c - 32;
		return (a);
	}
	else
		return (c);
}
