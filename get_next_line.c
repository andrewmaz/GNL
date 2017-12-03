/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:32:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/03 16:50:04 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, int size)
{
	char *nstr;
	

	if (!(nstr = (char*)malloc(sizeof(char) * size)))
		return (NULL);
		
	if (!(nstr = ft_strnew(size)))
		return (NULL);
	if (str)
	{
		ft_strcpy(nstr, str);
		free(str);
	}
	return (nstr);
}

t_list *ft_add2list(t_list **list, size_t fd)
{
	t_list *lst;

	lst = *list;
	if (!lst)
		return (ft_lstnew("", fd));
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
	static t_list *qwe;
	int ret;
	char buf[BUFF_SIZE + 1];
	int size;
	int i;

	size = 0;
	i = 0;
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	qwe = ft_add2list(&qwe, (size_t)fd);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		size += ret;		
		qwe->content = ft_realloc(qwe->content, size);
		qwe->content = ft_strcat(((char*)qwe->content), buf);
	}
	while (((char*)qwe->content)[i] != '\n' && ((char*)qwe->content)[i])
		i++;
	if (i)
	{
		*line = ft_strsub(qwe->content, 0, i);
		if (((char*)qwe->content)[i] == '\n')
			qwe->content = ft_strchr(qwe->content, '\n') + 1;
		else
			ft_strclr(qwe->content);
		return (1);
	}
	else
		return (0);
}
