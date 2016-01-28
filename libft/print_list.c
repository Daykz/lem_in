/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:03:36 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/24 18:21:11 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *list)
{
	if (list)
	{
		while (list)
		{
			ft_putstr((char *)list->data);
			ft_putchar('\n');
			list = list->next;
		}
	}
}
