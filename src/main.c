/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:24:53 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/22 12:24:58 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char **mas_line;
	char *map;

	if (ac > 2)
		return (ft_puterror(1, NULL, 0));
	if (ft_errorfile(av))
		return (0);
	if (!(mas_line = ft_fileread(av)))
		return (0);
	if (!(map = ft_tetris(mas_line)))
	{
		ft_freemas(mas_line);
		return (0);
	}
	ft_putstr(map);
	ft_freemas(mas_line);
	free(map);
	return (0);
}
