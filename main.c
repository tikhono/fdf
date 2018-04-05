/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/05 18:13:24 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "parser.h"
#include "line.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	if (ac < 2)
		return (1);
	while (ac > 2)
		if (fork() != 0)
			--ac;
		else
			break ;
	--ac;
	if (1)//parse(av[ac])
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

		draw_line(100, 100, 700, 300, mlx, win);
		draw_line(200, 200, 700, 300, mlx, win);
	///call_hookers;
		mlx_loop(mlx);
	}
	else
		ft_putstr("Invalid map");
	return (0);
}
