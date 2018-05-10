/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/10 18:14:40 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int 	exit_mouse(t_mlx *ptr)
{
	erase(ptr->s_pix);
	exit(0);
}

int		main(int ac, char **av)
{
	t_mlx	ptr;
	t_pix	***arr;

	if (ac < 2)
		return (1);
	while (ac > 2)
		if (fork() != 0)
			--ac;
		else
			break ;
	--ac;
	if ((arr = parse(av[ac])))
	{
		ptr.mlx = mlx_init();
		ptr.win = mlx_new_window(ptr.mlx, 1200, 600, ft_itoa(ac));
		ptr.s_pix = arr;
		ptr.scale = 10;
		ptr.ax = 0;
		ptr.ay = 0;
		ptr.az = 0;
		put_map(ptr, ptr.scale);
		mlx_hook(ptr.win, 2, 5, call_hookers, &ptr);
		mlx_hook(ptr.win, 17, 1L << 17, exit_mouse, &ptr);
		mlx_loop(ptr.mlx);
	}
	else
		ft_putstr("Invalid map");
	return (0);
}

//	img = mlx_new_image(mlx, 1200, 600);
//	adr = (int *)mlx_get_data_addr(img, &a, &b, &c);
//	adr[10] = 0xBFFF0000;
//	adr[11] = 0xBFFF0000;
//	adr[12] = 0xBFFF0000;
//	adr[13] = 0xBFFF0000;
//	adr[14] = 0xBFFF0000;
//	adr[15] = 0xBFFF0000;
//	adr[16] = 0xBFFF0000;
//	adr[17] = 0xBFFF0000;
//	mlx_put_image_to_window(mlx, win, img, 0, 0);

//	int		i;
//	int		j;
//	i = 0;
//	while (arr[i] != NULL)
//	{
//		j = 0;
//		while (arr[i][j] != NULL)
//		{
//			printf("%i %i  ", arr[i][j]->oz, arr[i][j]->color);
//			++j;
//		}
//		printf("\n");
//		++i;
//	}

//	0x00FF0000 //bright
//	0x1AFF0000
//	0x33FF0000
//	0x4DFF0000
//	0x66FF0000
//	0x80FF0000
//	0x99FF0000
//	0xA6FF0000
//	0xBFFF0000
//	0xD9FF0000 //dark


//	draw_line(100, 100, 100, 0, ptr.mlx, ptr.win);
//	draw_line(100, 100, 200, 0, ptr.mlx, ptr.win);
//	draw_line(100, 100, 200, 100, ptr.mlx, ptr.win);
//	draw_line(100, 100, 200, 200, ptr.mlx, ptr.win);
//	draw_line(100, 100, 100, 200, ptr.mlx, ptr.win);
//	draw_line(100, 100, 0, 200, ptr.mlx, ptr.win);
//	draw_line(100, 100, 0, 100, ptr.mlx, ptr.win);
//	draw_line(100, 100, 0, 0, ptr.mlx, ptr.win);
//
//	draw_line(100, 100, 150, 0, ptr.mlx, ptr.win);
//	draw_line(100, 100, 200, 50, ptr.mlx, ptr.win);
//	draw_line(100, 100, 200, 150, ptr.mlx, ptr.win);
//	draw_line(100, 100, 150, 200, ptr.mlx, ptr.win);
//	draw_line(100, 100, 50, 200, ptr.mlx, ptr.win);
//	draw_line(100, 100, 0, 150, ptr.mlx, ptr.win);
//	draw_line(100, 100, 0, 50, ptr.mlx, ptr.win);
//	draw_line(100, 100, 50, 0, ptr.mlx, ptr.win);
