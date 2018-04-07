/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:52:55 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/07 16:10:32 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct		s_pix
{
	int				x;
	int				y;	
	int				z;
	int				oz;
	int				color;
}					t_pix;

t_pix	***parse(char *file);

#endif
