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

int			check_path(t_room *room, t_infos *infos)
{
	int		i;

	i = 0;
	room->good_path = 1;
	if (!ft_strcmp(room->name, infos->end))
		return (1);
	while ((i < room->nbr_neighbors) && room->neighbors)
	{

	}
	return (0);
}

void		go_check_path(t_list *rooms, t_infos *infos)
{
	t_room *room;
	int		i;

	i = 0;
	(void)infos;
	room = rooms->data;
	while ((i < room->nbr_neighbors) && room->neighbors)
	{
		check_path(room->neighbors[i], infos);
		i++;
	}
}

void		check_good_path(t_list *rooms, t_infos *infos)
{
	t_room *room;

	if (rooms)
	{
		while (rooms)
		{
			room = rooms->data;
			if (!ft_strcmp(room->name, infos->start))
				go_check_path(rooms, infos);
			rooms = rooms->next;
		}
	}
}