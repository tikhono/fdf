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
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include "main.h"
# include "libft/libft.h"

typedef struct	s_pix
{
	double		x;
	double		y;
	double		z;
	double		oz;
}				t_pix;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	double		h_min;
	double		h_max;
	double		w_min;
	double		w_max;
	double		ax;
	double		ay;
	double		az;
	double		mx;
	double		my;
	int			scale;
	t_pix		***s_pix;
}				t_mlx;

t_pix			***parse(char *file);
void			draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win);
void			put_map(t_mlx ptr, int a);
int				call_hookers(int key, t_mlx *ptr);
t_pix			***erase(t_pix ***arr);

#endif
