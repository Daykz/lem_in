/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:53:57 by sksourou          #+#    #+#             */
/*   Updated: 2016/03/15 08:45:10 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int tablen(char **tab)
{
	return ((*tab) ? 1 + tablen(tab + 1) : 0);
}

static t_room 	*name_to_room(char const *name, t_list **list)
{
	t_list *room_list;
	t_room *room;

	room_list = *list;
	if (name && list)
	{
		while (room_list)
		{
			room = (room_list)->data;
			if (room->name && !ft_strcmp(room->name, name))
				return (room);
			room_list = room_list->next;
		}
	}
	return (NULL);
}

static void 	add_neighbor(t_room *room, t_room *neighbor)
{
	static	int	i = 0;
	int			j;
	if (room && neighbor)
	{
		if (room->neighbors[i])
		{
			i++;
		}
		room->neighbors[i] = (t_room *)malloc(sizeof(t_room) * 42);
		room->neighbors[i] = neighbor;
		room->nbr_neighbors++;
		j = i;
		while (j >= 0)
			j--;
	}

}

static int 		check_tubes(char *str, t_infos *infos, t_list **rooms)
{
	int len;
	char **split;
	t_room *left;
	t_room *right;
	(void)infos;

	if (str)
	{
		split = ft_strsplit(str, '-');
		len = tablen(split);
		if (len == 2)
		{
			if (!(left = name_to_room(split[0], rooms)))
				exit (0);
			if (!(right = name_to_room(split[1], rooms)))
				exit (0);
			if (left->nbr_neighbors == 0)
			{
				left->nbr_neighbors = 0;
				left->neighbors = (t_room **)malloc(sizeof(t_room *) * 42);
			}

			add_neighbor(left, right);
			return (1);
		}
		// PENSES A FREE LE **SPLIT
	}
	return (0);
}

static int		check_ants(char *str, t_infos *infos)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i++]) == 1)
	{
		if (!str[i])
		{
			infos->nbr_ants = ft_atoi(str);
			return (1);
		}
	}
	return (0);
}

static 	int		check_start(char *str, t_infos *infos)
{
	int i;
	char **split;

	i = 0;
	if (infos->a == -1)
	{
		split = ft_strsplit(str, ' ');
		infos->start = (char *)malloc(sizeof(char) * ft_strlen(split[0]) + 1);
		infos->start = split[0];
		infos->a++;
		return (1);
	}
	else if (ft_strcmp(str, "##start") == 0)
	{
		infos->a = -1;
		return (1);
	}
	return (0);
}

static	int	check_end(char *str, t_infos *infos)
{
	int i;
	char **split;

	i = 0;
	if (infos->z == -1)
	{
		split = ft_strsplit(str, ' ');
		infos->end = (char *)malloc(sizeof(char) * ft_strlen(split[0]) + 1);	
		infos->end = split[0];
		infos->z++;
		return (1);
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		infos->z = -1;
		return (1);
	}
	return (0);
}

int check_pos(char *str, t_list **rooms, t_infos *infos)
{
	char **split;
	int i;
	int j;

	j = 0;
	i = 0;
	if (infos->a > -1 && infos->ok != 2)
	{
		list_add_next(rooms, create_room(infos->start));
		infos->ok++;
	}
	if (infos->z > -1 && infos->ok != 2)
	{
		list_add_next(rooms, create_room(infos->end));
		infos->ok++;
	}
	if ((split = ft_strsplit(str, ' ')) == 0)
		return(0);
	while (i != 3 && ft_isasciis(split[i]) == 1)
		i++;
	if (i == 3)
	{
		list_add_next(rooms, create_room(split[0]));
		return (1);
	}
	return (0);
}

int		check_map(char *str, t_infos *infos, t_list **rooms)
{
	if (check_ants(str, infos) == 1)
		return (1);
	else if (check_start(str, infos) == 1 && infos->ok != 2)
	 	return (1);
	else if (check_end(str, infos) == 1 && infos->ok != 2)
	 	return (1);
	else if(check_pos(str, rooms, infos) == 1)
		return (1);
	else if(check_tubes(str, infos, rooms) == 1)
	 	return (1);
	return (0);
}
