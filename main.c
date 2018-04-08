/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/07 21:08:29 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "parser.h"
#include "line.h"
#include "libft/libft.h"
#include "printf.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	void	*mlx;
	void	*win;
	t_pix	***arr;

	if (ac < 2)
		return (1);
	while (ac > 2)
		if (fork() != 0)
			--ac;
		else
			break ;
	--ac;
	arr = parse(av[ac]);
	if (arr)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, 1200, 600, ft_itoa(ac));
		mlx_pixel_put(mlx, win, 100, 100, 0x00FF0000); //bright
		mlx_pixel_put(mlx, win, 90, 100, 0x1AFF0000);
		mlx_pixel_put(mlx, win, 80, 100, 0x33FF0000);
		mlx_pixel_put(mlx, win, 70, 100, 0x4DFF0000);
		mlx_pixel_put(mlx, win, 60, 100, 0x66FF0000);
		mlx_pixel_put(mlx, win, 50, 100, 0x80FF0000);
		mlx_pixel_put(mlx, win, 40, 100, 0x99FF0000);
		mlx_pixel_put(mlx, win, 30, 100, 0xA6FF0000);
		mlx_pixel_put(mlx, win, 20, 100, 0xBFFF0000);
		mlx_pixel_put(mlx, win, 10, 100, 0xD9FF0000); //dark

    //
	//	draw_line(100, 100, 200, 200, mlx, win);
	//	draw_line(100, 150, 500, 252, mlx, win);
	//	draw_line(100, 200, 500, 302, mlx, win);
	//	draw_line(100, 250, 500, 452, mlx, win);
	//	draw_line(100, 300, 500, 402, mlx, win);
	//	draw_line(100, 350, 500, 452, mlx, win);
	//	draw_line(100, 400, 500, 502, mlx, win);
	//	draw_line(100, 450, 500, 552, mlx, win);
	//	draw_line(100, 500, 500, 602, mlx, win);
	//	draw_line(100, 550, 500, 652, mlx, win);
	////call_hookers;
		i = 0;
		while (arr[i] != NULL)
		{
			j = 0;
			while (arr[i][j] != NULL)
			{
	//			printf("%i %i  ", arr[i][j]->oz, arr[i][j]->color);
				++j;
			}
	//		printf("\n");
			++i;
		}
		mlx_loop(mlx);
	}
	else
		ft_putstr("Invalid map");
	return (0);
}
