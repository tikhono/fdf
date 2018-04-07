/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/07 21:13:24 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "libft/libft.h"
#include <printf.h>

int		number_of_rows(int fd)
{
	int		end;
	int		res;
	char	*line;

	res = 0;
	end = 1;
	while (end != 0)
	{
		line = (char *)malloc(sizeof(char) * 256);
		end = read(fd, line, 256);
		if (end == -1)
			return (-1);
		line[end]= '\0';
		res += ft_count_chars(line, "\n");
	}
	close(fd);
	return (res);
}

t_pix	***fill(t_pix ***arr, int fd, int i, int j)
{
	char	*line;
	char	**temp;
	char	**buf;
	
	arr = NULL;	
	while (get_next_line(fd, &line))
	{
		buf = ft_strsplit(line, ' ');
		printf("here!\n");
		free(line);
		j = 0;
		arr[i] = (t_pix **)malloc(sizeof(t_pix *) * (ft_strlen(buf) + 1));//fix this shit mathafaka
		printf("here!\n");
		while (buf[j] != NULL)
		{
			temp = ft_strsplit(buf[j], ',');
			arr[i][j] = (t_pix *)malloc(sizeof(t_pix));
			arr[i][j]->oz = ft_atoi(temp[0]);
			if (temp[1])
			{
				arr[i][j]->color = 0x00000000 + ft_atoi(temp[1]);
				if (temp[2])
					return (NULL);//write free function
			}
			else
				arr[i][j]->color = 0x00FFFFFF;
			++j;
		}
		arr[i][j] = NULL;
		free(buf);
		++i;
	}
	close(fd);
	return (arr);
}

t_pix	***parse(char *file)
{
	int		fd;
	int		rows;
	char	*line;
	t_pix 	***arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0 || rows <= 0)
		return (0);
	arr = (t_pix ***)malloc(sizeof(t_pix **) * (rows + 1));
	arr[rows] = NULL;
	return (fill(arr, fd, 0, 0));
}
