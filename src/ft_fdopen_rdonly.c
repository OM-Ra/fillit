/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdopen_rdonly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:14:22 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/22 09:16:21 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fdopen_rdonly(char *av)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (ft_puterror(1, NULL, -1));
	return (fd);
}
