/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/01 12:41:43 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
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
	if (1)//parse(av[ac])
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, 1200, 600, ft_itoa(ac - 1));
		mlx_pixel_put(mlx, win, 100, 100, 0xFF0000);
		//call_hookers;
		mlx_loop(mlx);
	}
	else
		ft_putstr("Invalid map");
	return (0);
}
