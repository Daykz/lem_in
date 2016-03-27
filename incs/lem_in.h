/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:03:38 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/24 16:03:45 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_room
{
	char 			*name;
	int				nbr_neighbors;
	struct s_room	**neighbors;
	int				ant_nb;
	int				good_path;
}				t_room;

typedef struct s_infos
{
	int			ok;
	char		*start;
	char		*end;
	int			a;
	int 		z;
	int			nbr_ants;
}				t_infos;


void	print_rooms(t_list *rooms);
t_list *create_room(char const *name);
int 	ft_isasciis(char *str);
int 	ft_isdigits(char *str);
int		check_map(char *str, t_infos *infos, t_list **rooms);
void	stock_map(t_list *map, t_infos *infos, t_list **rooms);
void	check_good_path(t_list *rooms, t_infos *infos);

#endif