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
	infos->okstart = 0;
	infos->okend = 0;
	infos->a = -2;
	infos->z = -2;
	infos->paths = 0;
	infos->nbr_path = 0;
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

t_room	*go_end(t_list *rooms, t_infos *infos)
{
	t_room	*room;
	while (rooms)
	{
		room = rooms->data;
		if (!ft_strcmp(room->name, infos->end))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room	*go_entry(t_list *rooms, t_infos *infos)
{
	t_room	*room;
	while (rooms)
	{
		room = rooms->data;
		if (!ft_strcmp(room->name, infos->start))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

void	lem_in(t_list *rooms, t_infos *infos)
{
	t_room *room;

	if (rooms)
	{
		room = go_end(rooms, infos);
		room->good_path = 1;
		check_path(room, rooms, infos);
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
	lem_in(rooms, &infos);
	print_rooms(rooms);
	printf("nbr_path=%d\n", infos.nbr_path);
	return (0);
}