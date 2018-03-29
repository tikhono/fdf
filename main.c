/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/03/29 20:01:59 by atikhono         ###   ########.fr       */
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
	while (ac > 1)
		if (fork() != 0)
			--ac;
		else
			break ;
	if (1)//parse(av[ac])
	{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 600, "Ya okoshko");
	mlx_pixel_put(mlx, win, 100, 100, 0xFF0000);	
//call hookers
	mlx_loop(mlx);
	}
	else
		ft_putstr("Invalid");
	return (0);
}
