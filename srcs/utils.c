/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:43:08 by sksourou          #+#    #+#             */
/*   Updated: 2015/11/25 18:43:10 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	ft_isdigits(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
		}
 		else
			return (0);
	}
	return (1);
}

int 	ft_isasciis(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			i++;
 		else
			return (0);
	}
	return (1);
}


t_list *create_room(char const *name)
{
	t_list *new_link;
	t_room *room;

	if ((new_link = malloc(sizeof(*new_link))))
	{
		if ((room = malloc(sizeof(*room))))
		{
			room->name = ft_strdup(name);
			room->ant_nb = 0;
			room->neighbors = NULL;
			new_link->data = (void *)room;
		}
		else
		{
			free(new_link);
			return (NULL);
		}
	}
	return (new_link);
}

void	print_rooms(t_list *rooms)
{
	// attention roomS = t_list, room = t_room;
	t_room *room; //temporaire pour eviter le cast
	int i = 0;

	if (rooms)
	{
		while (rooms)
		{
			room = rooms->data;
			printf("ROOM[%d] = name: %s, ant_nb = %d, neightbors_ptr = %p\n", i, room->name, room->ant_nb, room->neighbors);
			rooms = rooms->next;
			i++;
		}
	}
}
