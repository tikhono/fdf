/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/05/14 16:15:12 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		exit_mouse(void)
{
	exit(0);
}

void	put_help(t_mlx p)
{
	void	*win;

	win = mlx_new_window(p.mlx, 200, 150, "HELP");
	mlx_string_put(p.mlx, win, 10, 10, 0xFFFFFF, "Q and A - rot x\n");
	mlx_string_put(p.mlx, win, 10, 30, 0xFFFFFF, "W and S - rot y\n");
	mlx_string_put(p.mlx, win, 10, 50, 0xFFFFFF, "E and D - rot z\n");
	mlx_string_put(p.mlx, win, 10, 70, 0xFFFFFF, "R and F - zoom\n");
	mlx_string_put(p.mlx, win, 10, 90, 0xFFFFFF, "Arrows  - move\n");
	mlx_hook(p.win, 2, 5, call_hookers, &p);
	mlx_hook(p.win, 17, 1L << 17, exit_mouse, &p);
}

void	initialise(t_mlx *ptr, t_pix ***arr, int ac)
{
	char *a;

	a = ft_itoa(ac);
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1200, 600, a);
	ptr->s_pix = arr;
	ptr->scale = 10;
	ptr->ax = 0;
	ptr->ay = 0;
	ptr->az = 0;
	free(a);
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
		initialise(&ptr, arr, ac);
		put_help(ptr);
		put_map(ptr);
		mlx_hook(ptr.win, 2, 5, call_hookers, &ptr);
		mlx_hook(ptr.win, 17, 1L << 17, exit_mouse, &ptr);
		mlx_loop(ptr.mlx);
	}
	else
	{
		ft_putstr("Invalid map");
		system("leaks fdf");
	}
	return (0);
}
