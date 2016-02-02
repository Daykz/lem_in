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

void		create_link(char *str, t_list **rooms)
{
	int		i;

	i = 0;
	
}

void		link_rooms(t_infos *infos, t_list **rooms)
{
	int		j;

	j = 0;
	while (infos->tubes[j] != NULL)
	{
		create_link(infos->tubes[j], rooms);
		//printf("tube=%s\n", infos->tubes[j]);
		j++;
	}
}