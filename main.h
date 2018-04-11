/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:41:57 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/10 17:45:22 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H
# define FACTOR 3.9015625

typedef struct		s_pix
{
	int				x;
	int				y;	
	int				z;
	int				oz;
	int				color;
}					t_pix;

t_pix	***parse(char *file);
int		ipart(double x);
int		rpart(double x);
double	fpart(double x);
double	rfpart(double x);
void	draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win);
int		call_hookers(int key, t_pix ***arr);
t_pix	***erase(t_pix ***arr);

#endif
