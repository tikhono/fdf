/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:56:24 by atikhono          #+#    #+#             */
/*   Updated: 2018/03/29 17:11:13 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(int ac, char **av)
{
	if (!parce())
		return (1);
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1200, 600, "Ya okoshko");
	mlx_pixel_put(mlx, win, 100, 100, 0xFF0000);	
	//call hookers
	mlx_loop(mlx);

	return (0);
}
