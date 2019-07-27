/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 10:39:38 by apappas           #+#    #+#             */
/*   Updated: 2019/07/27 13:43:24 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static g_list	*getfile(g_list **stat, int fd)
{
	g_list *find;
	g_list	*new;

	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			return (find);
		find = find->next;
	}
	new  = (g_list *)ft_memalloc(sizeof(g_list));
	new->content = ft_strnew(0);
	new->fd = fd;
	new->next = *stat;
	*stat = new;
	return (new);
}

static	int		read_file(g_list **temp, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		readret;

	while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readret] = '\0';
		(*temp)->content = ft_strjoin((*temp)->content, buf);
		if (ft_strchr(buf, '\n'))
			break;
		ft_strclr(buf);
	}
	if (readret == 0)
		return (0);
	else if (readret < 0)
		return (-1);
	else
		return (1);
}

static char		*get_line(g_list **temp, g_list **stat, int fd)
{
	char	*ptr;
	char	*line;
	g_list	*find;

	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			break;
		find = find->next;
	}
	if ((ptr = ft_strchr((*temp)->content, '\n')))
	{
		*ptr = '\0';
		find->content = ft_strjoin(find->content, (ptr + 1));
		line = ft_strdup((*temp)->content);
	}
	if (!(ptr = ft_strchr((*temp)->content, '\n')))
	{
		line = ft_strdup((*temp)->content);
	}
	return (line);
}

static void		to_free(g_list **stat, int fd)
{
	g_list	*find;
	g_list	*temp;

	find = *stat;
	if (*stat == NULL)
		return ;
	while (find->next->fd != fd)
	{
		if (find->next == NULL)
			return ;
		find = find->next;
	}
	temp = find->next;
	find->next = find->next->next;
	free(&(temp)->content);
	free(&(temp)->fd);
	free(temp);
}


int	get_next_line(const int fd, char **line)
{
	static g_list	*stat;
	g_list	*temp;
	char	buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	if (!(temp = getfile(&stat, fd)))
		return (-1);
	if ((read_file(&temp, fd)) >= 0)
		*line = get_line(&temp, &stat, fd);
	if (!ft_strlen(temp->content))
	{
		to_free(&stat, fd);
		return (0);
	}
	return (1);
}
