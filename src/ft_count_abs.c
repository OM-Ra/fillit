/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:51:05 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/04 10:51:10 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_abs(char *map)
{
	int abs;

	abs = 0;
	while (map[abs] != '\n')
		abs++;
	return (abs);
}
