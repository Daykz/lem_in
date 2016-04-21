/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 19:14:24 by dmathe            #+#    #+#             */
/*   Updated: 2016/02/02 19:14:25 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_link(t_room *prev, t_room *room)
{
	int	i;

	i = 0;
	room->neighbors[0] = NULL;
	room->nbr_neighbors = 0;
	while (i < prev->nbr_neighbors)
	{
		if (!ft_strcmp(prev->neighbors[i]->name, room->name))
		{
			while (i + 1 < prev->nbr_neighbors)
			{
				prev->neighbors[i] = prev->neighbors[i + 1];
				i++;
			}
			prev->neighbors[i--] = NULL;
			prev->nbr_neighbors--;
		}
		i++;
	}
}

int		check_if_start(t_room *room, t_infos *infos)
{
	int	i;

	i = 0;
	while (i < room->nbr_neighbors)
	{
		if (!ft_strcmp(room->neighbors[i]->name, infos->start))
		{
			room->neighbors[i]->good_path = 1;
			infos->nbr_path++;
			printf("nbr_path=%d, name=%s\n", infos->nbr_path, room->neighbors[i]->name);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_good(t_room *prev, t_room *room, t_list *rooms, t_infos *infos)
{
	int	i;

	i = 0;
	infos->paths++;
	while (i < room->nbr_neighbors)
	{
		printf("room[%s]=%d\n", room->name, infos->paths);
		printf("room->name=%s, nbr_neighbors=%d\n", room->name, room->nbr_neighbors);
		printf("room->neighbors=%s, good_path=%d\n", room->neighbors[i]->name, room->neighbors[i]->good_path);
		if (!ft_strcmp(prev->name, room->neighbors[i]->name))
			;
		else if (check_if_start(room, infos) == 1)
		{
			infos->paths = 0;
			check_path(go_end(rooms, infos), rooms, infos);
		}
		else if (!room->neighbors[i]->good_path)
		{
			room->neighbors[i]->good_path = infos->paths;
			check_good(room, room->neighbors[i], rooms, infos);
		}
		else if (infos->paths < room->neighbors[i]->good_path)
		{
			room->neighbors[i]->good_path = infos->paths;
			check_good(room, room->neighbors[i], rooms, infos);
		}
		i++;	
	}
	check_path(go_end(rooms, infos), rooms, infos);
}

int		check_no_way(t_list *rooms, t_infos *infos)
{
	t_room *room;

	while (rooms)
	{
		room = rooms->data;
		if (room->nbr_neighbors == 1 && ft_strcmp(room->name, infos->start))
		{
			delete_link(room->neighbors[0], room);
			return (1);
		}
		rooms = rooms->next;
	}
	return (0);
}

void	check_path(t_room *room, t_list *rooms, t_infos *infos)
{
	int	i;

	i = 0;
	while (check_no_way(rooms, infos) == 1)
		;
	printf("START 'room[%s]'\n", room->name);
	while (i < room->nbr_neighbors)
	{
		printf("good_path=%d\n", room->neighbors[i]->good_path);
		if (!room->neighbors[i]->good_path)
		{
			printf("SALUT\n");
			room->neighbors[i]->good_path = 1;
			check_good(room, room->neighbors[i], rooms, infos);
		}
		i++;
	}
}