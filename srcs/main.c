/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:03:54 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/24 16:03:55 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	init(t_infos *infos)
{
	infos->nbr_ants = 0;
	infos->ok = 0;
	infos->a = 0;
	infos->z = 0;
}

void	stock_map(t_list *map, t_infos *infos, t_list **rooms)
{
	char *line;

	while(get_next_line(0, &line) != 0)
	{
		list_add_next(&map, link_init((void *)line));
		if (check_map(line, infos, rooms) == 0)
				break ;
	}
	print_list(map);
	printf("\n");
}

void	put_ant(t_room *neighbor)
{
	printf("name = %s, nbr_ants = %d, ptr = %p\n", neighbor->name, neighbor->ant_nb, neighbor);
}

void	go_entry(t_list *rooms, t_infos *infos)
{
	t_room *room;
	int 	i;

	i = 0;
	(void)infos;
	room = rooms->data;
	while ((i < room->nbr_neighbors) && room->neighbors)
	{
		put_ant(room->neighbors[i]);
		i++;
	}
}

void	lem_in(t_list *rooms, t_infos *infos)
{
	t_room *room;

	if (rooms)
	{
		while (rooms)
		{
			room = rooms->data;
			if (!ft_strcmp(room->name, infos->start))
				go_entry(rooms, infos);
			rooms = rooms->next;
		}
	}
}

int		main(void)
{
	t_list	*map;
	t_infos	infos;
	t_list	*rooms;

	rooms = NULL;
	map = NULL;
	init(&infos);
	stock_map(map, &infos, &rooms);
	print_rooms(rooms);
	check_good_path(rooms, &infos);
	//lem_in(rooms, &infos);
	return (0);
}