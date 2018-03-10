/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:03:37 by atikhono          #+#    #+#             */
/*   Updated: 2018/03/10 13:41:50 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_node(const int fd, char *buff, t_llist **head)
{
	t_llist	*new;
	t_llist	*cur;

	new = (t_llist *)malloc(sizeof(t_llist));
	if (new != NULL)
	{
		cur = *head;
		if (cur == NULL)
			*head = new;
		else
		{
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new;
		}
		new->next = NULL;
		new->buff = ft_strdup(buff);
		new->fd = fd;
	}
}

void	del_node(const int fd, t_llist **head, t_llist *cur, t_llist *to_free)
{
	if (*head != NULL && (cur = *head))
	{
		if (cur->fd == fd)
		{
			*head = cur->next;
			free(cur->buff);
			cur->buff = NULL;
			free(cur);
		}
		else
			while (cur->next != NULL)
			{
				if (cur->next->fd == fd)
				{
					free(cur->next->buff);
					cur->next->buff = NULL;
					to_free = cur->next;
					cur->next = cur->next->next;
					free(to_free);
					break ;
				}
				cur = cur->next;
			}
	}
}

char	*find_fd_buff(const int fd, t_llist **head, ssize_t *z)
{
	t_llist	*cur;
	char	*before_n;

	cur = *head;
	while (cur != NULL)
	{
		if (cur->fd == fd)
		{
			before_n = ft_strdup(cur->buff);
			del_node(fd, head, NULL, NULL);
			return (before_n);
		}
		cur = cur->next;
	}
	before_n = ft_strnew(BUFF_SIZE);
	if ((*z = read(fd, before_n, BUFF_SIZE)) == -1)
	{
		free(before_n);
		return (NULL);
	}
	return (before_n);
}

int		fill_line(const int fd, char **line, t_llist **head, ssize_t z)
{
	t_operator	cur;

	while (z != 0)
		if (!(cur.temp = find_fd_buff(fd, head, &z)))
			return (-1);
		else if ((cur.n = ft_strchr(cur.temp, '\n')))
		{
			*cur.n = '\0';
			cur.to_free = *line;
			*line = ft_strjoin(*line, cur.temp);
			if (*(cur.n + 1) != '\0')
				add_node(fd, cur.n + 1, head);
			free(cur.to_free);
			free(cur.temp);
			return (1);
		}
		else
		{
			cur.to_free = *line;
			*line = ft_strjoin(*line, cur.temp);
			free(cur.temp);
			free(cur.to_free);
		}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static t_llist	*head;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	ret = fill_line(fd, line, &head, 1);
	if (ret != 0)
		return (ret);
	if (**line)
		return (1);
	del_node(fd, &head, NULL, NULL);
	return (0);
}
