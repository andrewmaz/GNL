/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:32:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/04 16:39:43 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = ft_strnew(size)))
		return (NULL);
	ft_strcpy(nstr, str);
	if (str && ft_strlen(str))
		free(str);
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

int get_next_line(const int fd, char **line)
{
	static t_list *head;
	int ret;
	char buf[BUFF_SIZE + 1];
	int size;
	t_list *qwe;

	size = 0;
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	qwe = ft_add2list(&head, (size_t)fd);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		size += ret;
		qwe->content = ft_realloc(qwe->content, size);
		qwe->content = ft_strcat(((char*)qwe->content), buf);
	}
	size = 0;
	while (((char*)qwe->content)[size] != '\n' && ((char*)qwe->content)[size])
		size++;
	if (size || ((char*)qwe->content)[size] == '\n')
	{
		*line = ft_strsub(qwe->content, 0, size);
		if (((char*)qwe->content)[size] == '\n')
			qwe->content = ft_strchr(qwe->content, '\n') + 1;
		else
		{
			ft_strclr(qwe->content);
			//free(qwe->content);
		}
		return (1);
	}
	else
		return (0);
}
