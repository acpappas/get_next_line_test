/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 10:39:38 by apappas           #+#    #+#             */
/*   Updated: 2019/09/02 14:07:39 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_listg		*getfile(t_listg **stat, int fd)
{
	t_listg *find;
	t_listg	*new;

	if (!*stat)
		*stat = NULL;
	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			return (find);
		find = find->next;
	}
	new = (t_listg *)ft_memalloc(sizeof(t_listg));
	new->content = ft_strnew(0);
	new->fd = fd;
	new->next = *stat;
	*stat = new;
	return (new);
}

char		*get_line(t_listg **temp)
{
	char	*ptr;
	char	*line;
	t_listg	*node;

	line = NULL;
	node = *temp;
	if ((ptr = ft_strchr((*temp)->content, '\n')))
	{
		*ptr = '\0';
		line = ft_strdup((*temp)->content);
		node->content = ft_strcpy(node->content, (ptr + 1));
		return (line);
	}
	line = ft_strdup((*temp)->content);
	ft_strclr(node->content);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_listg	*stat;
	t_listg			*temp;
	char			buf[BUFF_SIZE + 1];
	int				readret;
	char			*store;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	temp = getfile(&stat, fd);
	while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readret] = '\0';
		store = ft_strdup(temp->content);
		free(temp->content);
		temp->content = ft_strjoin(store, buf);
		free(store);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (readret == 0 && !ft_strlen(temp->content))
			return (0);
	*line = get_line(&temp);
	return (1);
}
