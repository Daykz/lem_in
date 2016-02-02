/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:53:57 by sksourou          #+#    #+#             */
/*   Updated: 2015/11/25 15:53:58 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int 		check_tubes(char *str, t_infos *infos)
{
	int i;
	static int j = 0;

	i = 0;
	while(ft_isdigit(str[i]) == 1)
		i++;
	if (str[i++] != '-')
		return (0);
	while(ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0')
	{
		infos->tubes[j] = (char *)malloc(sizeof(char) * 20);
		infos->tubes[j] = str;
		j++;
		return (1);
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
	if (infos->start == -1)
	{
		split = ft_strsplit(str, ' ');
		infos->start = ft_atoi(split[0]);
		return (1);
	}
	else if (ft_strcmp(str, "##start") == 1)
	{
		infos->start = -1;
		return (1);
	}
	return (0);
}

static	int	check_end(char *str, t_infos *infos)
{
	int i;
	char **split;

	i = 0;
	if (infos->end == -1)
	{
		split = ft_strsplit(str, ' ');
		infos->end = ft_atoi(split[0]);
		return (1);
	}
	else if (ft_strcmp(str, "##end") == 1)
	{
		infos->end = -1;
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
	if (infos->start > -1 && infos->ok != 2)
	{
		list_add_next(rooms, create_room(ft_itoa(infos->start)));
		infos->ok++;
	}
	if (infos->end > -1 && infos->ok != 2)
	{
		list_add_next(rooms, create_room(ft_itoa(infos->end)));
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
	else if(check_tubes(str, infos) == 1)
	 	return (1);
	return (0);
}
