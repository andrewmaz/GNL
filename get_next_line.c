/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:32:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/06 19:45:31 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = ft_strnew(size)))
		return (NULL);
	if (str)
	{
		ft_strcpy(nstr, str);
		//free(str);
	}
	return (nstr);
}

t_list *ft_add2list(t_list **list, size_t fd)
{
	t_list *lst;

	lst = *list;
	if (!(*list))
	{
		*list = ft_lstnew("", fd);
		return (*list);
	}
	while (lst->next && lst->content_size != fd)
		lst = lst->next;
	if (lst->content_size == fd)
		return (lst);
	else
	{
		lst->next = ft_lstnew("", fd);
		return (lst->next);
	}
}

int ft_add2line(t_list *lst, char **line)
{
	int i;
	int len;

	i = 0;
	if (*line)
		len = ft_strlen(*line);
	else
		len = 0;
	while (((char*)lst->content)[i] && ((char*)lst->content)[i] != '\n')
		i++;
	*line = ft_realloc(*line, len + i);
	*line = ft_strcat(*line, ft_strsub(lst->content, 0, i));
	if (((char*)lst->content)[i] == '\n')
	{
		lst->content = ft_strchr(lst->content, '\n') + 1;
		return (1);
	}
	else
	{
		ft_strclr(lst->content);
		//free(lst->content);
		return (0);
	}
}

int get_next_line(const int fd, char **line)
{
	static t_list *head;
	int ret;
	char buf[BUFF_SIZE + 1];
	int size;
	t_list *qwe;

	size = 0;
	ft_strclr(*line);
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	qwe = ft_add2list(&head, (size_t)fd);
	if (ft_add2line(qwe, line))
		return (1);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		size += ret;
		qwe->content = ft_realloc(qwe->content, size);
		qwe->content = ft_strcat(((char*)qwe->content), buf);
		if (ft_add2line(qwe, line))
			return (1);
	}
	if (*line && *line[0])
		return (1);
	else
		return (0);
}
