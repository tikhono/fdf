/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/03/26 18:39:16 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(int ac, char **av)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1200, 600, "Ya okoshko");
	mlx_pixel_put(mlx, win, 100, 100, 0xFF0000);	
	mlx_loop(mlx);

	//call parser
	//initialise window
	//call hookers
	//call loop to loop

	return (0);
}
