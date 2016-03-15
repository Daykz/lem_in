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

typedef struct  s_link
{
	struct s_link	*next;
	struct s_room	*target;
}				t_link;

typedef struct s_room // data du t_list
{
	char 			*name;		// name
	struct s_room	**neighbors; // liens vers tous les voisins
	int				ant_nb;		// nombre de fourmis
}				t_room;

typedef struct s_infos
{
	int			ok;
	int 		start;
	int 		end;
	int			nbr_ants;
	char		**tubes;
}				t_infos;

// void	room_add_next(t_room **room, t_room *link);
void	print_rooms(t_list *rooms);
t_list *create_room(char const *name);
int 	ft_isasciis(char *str);
int 	ft_isdigits(char *str);
int		check_map(char *str, t_infos *infos, t_list **rooms);
void	stock_map(t_list *map, t_infos *infos, t_list **rooms);

#endif