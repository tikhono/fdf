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

void	put_help(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 200, "HELP");
	mlx_string_put(mlx, win, 10, 10, 0xFFFFFF, "Scroll up/down to"" zoom int");
}

void	initialise(t_mlx *ptr, t_pix ***arr, int ac)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1200, 600, ft_itoa(ac));
	put_help();
	ptr->s_pix = arr;
	ptr->scale = 10;
	ptr->ax = 0;
	ptr->ay = 0;
	ptr->az = 0;
}

int		exit_mouse(t_mlx *ptr)
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
		initialise(&ptr, arr, ac);
		put_map(ptr);
		mlx_hook(ptr.win, 2, 5, call_hookers, &ptr);
		mlx_hook(ptr.win, 17, 1L << 17, exit_mouse, &ptr);
		mlx_loop(ptr.mlx);
	}
	else
		ft_putstr("Invalid map");
	return (0);
}
