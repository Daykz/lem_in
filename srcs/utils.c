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

void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

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
			room->nbr_neighbors = 0;
			room->good_path = 0;
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
	t_room *room;
	int 	i;

	if (rooms)
	{
		while (rooms)
		{
			room = rooms->data;
			printf("name = %s, path = %d\n", room->name, room->good_path);
			i = 0;
			while (room->neighbors && room->neighbors[i])
			{
				printf("neighbors=%p, %s\n", room->neighbors[i], room->neighbors[i]->name);
				i++;
			}
			rooms = rooms->next;
		}
	}
}
