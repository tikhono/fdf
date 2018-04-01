/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/01 15:53:27 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int		number_of_rows(int fd)
{
	int		end;
	int		res;
	char	*line;

	res = 0;
	end = read(256, line);
	if (end != -1)
		end 
	while ()

	return (res);
}

int		parse(char *file)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	if (rows < 0)
		return (0);
	get_next_line(fd, &line);




	return (1);
