/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 10:52:13 by apappas           #+#    #+#             */
/*   Updated: 2019/07/30 10:47:57 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "./libft/libft.h"

typedef struct		s_listg
{
	char			*content;
	int				fd;
	struct s_listg	*next;
}					t_listg;

int					get_next_line(const int fd, char **line);

#endif
